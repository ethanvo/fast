#!/usr/bin/env python
from pyscf import gto
import numpy as np
from numpy.linalg import multi_dot
from scipy.linalg import eigh
from math_tools import get_Fock_G
from math_tools import get_density_matrix

###############################################################################
# Specify a molecule
###############################################################################
mol = gto.Mole()
mol.verbose = 7
mol.atom = [
        ['O', (  0.0000,  0.0000,  0.1147)],
        ['H', (  0.0000,  0.7540, -0.4588)],
        ['H', (  0.0000, -0.7540, -0.4588)]]
mol.basis = 'sto-3g'
mol.build()

###############################################################################
# Calculate all required molecular integrals
###############################################################################
nbas = mol.nao_nr()
nelectron = mol.nelectron

S = gto.getints('cint1e_ovlp_sph', mol._atm, mol._bas, mol._env)
V_nucl = gto.getints('cint1e_nuc_sph', mol._atm, mol._bas, mol._env)
T = gto.getints('cint1e_kin_sph', mol._atm, mol._bas, mol._env)
eris = gto.getints('cint2e_sph', mol._atm, mol._bas, mol._env)

H_core = V_nucl + T

###############################################################################
# Diagonalize S and obtain transformation matrix X; X = Us^{-\frac{1}{2}}
# Canonical orthogonalization
# S is Hermitian
###############################################################################
from math_tools import canonical_orthogonalization
X = canonical_orthogonalization(S)

###############################################################################
# Obtain a guess density matrix P
# Simplest possible guess is null
###############################################################################
dtype = S.dtype
P = np.zeros((nbas, nbas), dtype=dtype)
conv = False

while not conv:
###############################################################################
# Calculate matrix G from P and eris
###############################################################################
    G = get_Fock_G(P, eris)

###############################################################################
# Add G to core Hamiltonian to obtain the Fock matrix F = H_core + G
###############################################################################
    F = H_core + G

###############################################################################
# Calculate the transformed Fock matrix F' = X^\dagFX
###############################################################################
    F_prime = multi_dot([X.conj().T, F, X])

###############################################################################
# Diagonalize F' to obtain C' and epsilon
###############################################################################
    epsilon, C_prime = eigh(F_prime)

###############################################################################
# Calculate C = XC'
###############################################################################
    C = np.dot(X, C_prime)

###############################################################################
# P_{mu, nu} = 2\sum^{\frac{N}{2}}_aC_{mu, a}C^*{nu, a}
###############################################################################
    P_prime = get_density_matrix(C, nelectron)

###############################################################################
# Check Convergence delta less than 1.0E-4
###############################################################################
    if (np.sum(np.abs(P_prime - P)) / nbas) < 1e-6:
        conv = True
    else:
        P = P_prime

E = 0.5 *np.sum
