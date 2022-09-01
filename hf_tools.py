#!/usr/bin/env python
from scipy.linalg import eigh
from numpy.linalg import multi_dot
from numpy import dot
import numpy as np
from opt_einsum import contract


def symmetric_orthogonalization_explicit(S):
    s, U = eigh(S)
    X = multi_dot([U, np.diag(s**-0.5), U.conj().T])
    return X


def symmetric_orthogonalization(S):
    s, U = eigh(S)
    X = contract("ij,j,kj", U, s**-0.5, U.conj())
    return X


def canonical_orthogonalization_explicit(S):
    s, U = eigh(S)
    X = dot(U, np.diag(s**-0.5))
    return X


def canonical_orthogonalization(S):
    s, U = eigh(S)
    X = contract("ij,j->ij", U, s**-0.5)
    return X


def get_Fock_G_explicit(P, eris):
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


def get_Fock_G(P, eris):
    G = contract("ij,klji", P, eris - 0.5 * eris.transpose(0, 3, 2, 1))
    return G


def get_density_matrix_explicit(C, nelectron):
    nbas = C.shape[0]
    dtype = C.dtype
    P = np.zeros((nbas, nbas), dtype=dtype)
    for mu in range(nbas):
        for nu in range(nbas):
            for a in range(int(np.ceil(nelectron / 2))):
                P[mu, nu] = P[mu, nu] + 2 * C[mu, a] * C.conj()[nu, a]
    return P


def get_density_matrix(C, nelectron):
    a = list(range(int(np.ceil(nelectron / 2))))
    P = 2 * contract("ia,ja", C[:, a], C[:, a].conj())
    return P


def get_electronic_energy_explicit(P, H_core, F):
    nbas = P.shape[0]
    E_0 = 0
    for mu in range(nbas):
        for nu in range(nbas):
            E_0 = E_0 + 0.5 * P[nu, mu] * (H_core[mu, nu] + F[mu, nu])
    return E_0


def get_electronic_energy(P, H_core, F):
    E_0 = 0.5 * contract("ji,ij", P, H_core + F)
    return E_0
