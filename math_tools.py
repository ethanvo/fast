#!/usr/bin/env python
from scipy.linalg import eigh
from numpy.linalg import multi_dot
from numpy import dot
import numpy as np


def symmetric_orthogonalization(S):
    s, U = eigh(S)
    X = multi_dot([U, np.diag(s**-0.5), U.conj().T])
    return X


def canonical_orthogonalization(S):
    s, U = eigh(S)
    X = dot(U, np.diag(s**-0.5))
    return X




def get_Fock_G(P, eris):
    dtype = eris.dtype
    nbas = P.shape[0]
    G = np.zeros((nbas, nbas), dtype=dtype)
    for mu in range(nbas):
        for nu in range(nbas):
            for lam in range(nbas):
                for sig in range(nbas):
                    G[mu, nu] = G[mu, nu] + P[lam, sig] * (
                        eris[mu, nu, sig, lam] - 0.5 * eris[mu, lam, sig, nu]
                    )
    return G




def get_density_matrix(C, nelectron):
    nbas = C.shape[0]
    dtype = C.dtype
    P = np.zeros((nbas, nbas), dtype=dtype)
    for mu in range(nbas):
        for nu in range(nbas):
            for a in range(int(np.ceil(nelectron / 2))):
                P[mu, nu] = P[mu, nu] + 2 * C[mu, a] * C.conj()[nu, a]
    return P




def get_electronic_energy(P, H_core, F):
    nbas = P.shape[0]
    E_0 = 0
    for mu in range(nbas):
        for nu in range(nbas):
            E_0 = E_0 + 0.5 * P[nu, mu] * (H_core[mu, nu] + F[mu, nu])
    return E_0
