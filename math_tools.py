#!/usr/bin/env python
###############################################################################
# Canonical Orthogonalization
# X = Us^{-\frac{1}{2}}
# S is Hermitian
###############################################################################
from scipy.linalg import eigh
import numpy as np
def canonical_orthogonalization(S):
    dtype = S.dtype
    nbas = S.shape[0]
    print('S dtype is {}'.format(dtype))
    print('nbas is {}'.format(nbas))
    s, U = eigh(S)
    X = np.zeros((nbas, nbas), dtype=dtype)
    for j in range(nbas):
        X[:, j] = U[:, j] * (s[j] ** -0.5)
    return X

###############################################################################
# Get two electron part of the Fock matrix G
# G_{mu,nu} = \sum_{lam,sig}[(mu, nu|sig, lam) - \frac{1}{2}(mu, lam|sig, nu)]
###############################################################################
import numpy as np
def get_Fock_G(P, eris):
    dtype = eris.dtype
    nbas = P.shape[0]
    print('G dtype is {}'.format(dtype))
    print('nbas is {}'.format(nbas))
    G = np.zeros((nbas, nbas), dtype=dtype)
    for lam in range(nbas):
        for sig in range(nbas):
            G = G + P[lam, sig] * (eris[:, :, sig, lam] - 0.5 * eris[:, lam, sig, :])
    return G

###############################################################################
# Get density matrix, P P_{mu, nu} = 2\sum^{\frac{N}{2}}_aC_{mu, a}C^*{nu, a}
###############################################################################
import numpy as np
def get_density_matrix(C, nelectron):
    a = int(np.ceil(nelectron / 2))
    P = np.dot(C[:, :a], C[:, :a].conj().T)
    return P

