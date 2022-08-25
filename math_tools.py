#!/usr/bin/env python
###############################################################################
# Canonical Orthogonalization
# X = Us^{-\frac{1}{2}}
# S is Hermitian
###############################################################################
from scipy.linalg import eigh
from numpy.linalg import multi_dot
from numpy import dot
def symmetric_orthogonalization(S):
    s, U = eigh(S)
    X = multi_dot([U, np.diag(s ** -0.5), U.conj().T])
    print(X)
    return X

###############################################################################
# Symmetric Orthogonalization
# 
###############################################################################
def canonical_orthogonalization(S):
    s, U = eigh(S)
    X = dot(U, np.diag(s ** -0.5))
    print(X)
    return X

###############################################################################
# Get two electron part of the Fock matrix G
# G_{mu,nu} = \sum_{lam,sig}[(mu, nu|sig, lam) - \frac{1}{2}(mu, lam|sig, nu)]
###############################################################################
import numpy as np
def get_Fock_G(P, eris):
    dtype = eris.dtype
    nbas = P.shape[0]
    G = np.zeros((nbas, nbas), dtype=dtype)
    for mu in range(nbas):
        for nu in range(nbas):
            for lam in range(nbas):
                for sig in range(nbas):
                    G[mu, nu] = G[mu, nu] + P[lam, sig] * (eris[mu, nu, sig, lam] - 0.5 * eris[mu, lam, sig, nu])
    return G

###############################################################################
# Get density matrix, P P_{mu, nu} = 2\sum^{\frac{N}{2}}_aC_{mu, a}C^*{nu, a}
###############################################################################
import numpy as np
def get_density_matrix(C, nelectron):
    nbas = C.shape[0]
    dtype = C.dtype
    P = np.zeros((nbas, nbas), dtype=dtype)
    for mu in range(nbas):
        for nu in range(nbas):
            for a in range(int(np.ceil(nelectron / 2))):
                P[mu, nu] = P[mu, nu] + 2 * C[mu, a] * C.conj()[nu, a]
    return P

###############################################################################
# Get electronic energy
# E_0 = \frac{1}{2}\sum_{mu}\sum_{nu}P_{nu mu}(H_core_{mu nu} + F_{mu nu})
###############################################################################
import numpy as np
def get_electronic_energy(P, H_core, F):
    nbas = P.shape[0]
    E_0 = 0
    for mu in range(nbas):
        for nu in range(nbas):
            E_0 = E_0 + 0.5 * P[nu, mu] * (H_core[mu, nu] + F[mu, nu])
    return E_0
