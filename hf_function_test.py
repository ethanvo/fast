#!/usr/bin/env python
from pyscf import gto
import numpy as np
from numpy.linalg import multi_dot
from scipy.linalg import eigh
from hf_tools import get_Fock_G, get_density_matrix, get_electronic_energy
from hf_tools import symmetric_orthogonalization
from hf_tools import symmetric_orthogonalization_explicit
from hf_tools import canonical_orthogonalization
from hf_tools import canonical_orthogonalization_explicit

mol = gto.Mole()
mol.verbose = 7
mol.atom = [
    ["O", (0.0000, 0.0000, 0.116)],
    ["H", (0.0000, 0.749, -0.463)],
    ["H", (0.0000, -0.749, -0.463)],
]
mol.basis = "sto3g"
mol.build()

E_nuc = mol.energy_nuc()

nbas = mol.nao_nr()
nelectron = mol.nelectron

S = gto.getints("cint1e_ovlp_sph", mol._atm, mol._bas, mol._env)
V_nucl = gto.getints("cint1e_nuc_sph", mol._atm, mol._bas, mol._env)
T = gto.getints("cint1e_kin_sph", mol._atm, mol._bas, mol._env)
eris = gto.getints("cint2e_sph", mol._atm, mol._bas, mol._env)

H_core = V_nucl + T
"""
X = symmetric_orthogonalization_explicit(S)
print(X)
X = symmetric_orthogonalization(S)
print(X)
"""
X = canonical_orthogonalization_explicit(S)
print(X)
X = canonical_orthogonalization(S)
print(X)
