#!/usr/bin/env python
import numpy as np
from opt_einsum import contract


def ao2mo_explicit(C, eris):
    nbas = C.shape[0]
    eris_mo = np.zeros((nbas, nbas, nbas, nbas))
    for kappa in range(nbas):
        for lam in range(nbas):
            for mu in range(nbas):
                for nu in range(nbas):
                    for p in range(nbas):
                        for q in range(nbas):
                            for r in range(nbas):
                                for s in range(nbas):
                                    eris_mo[p, q, r, s] += (
                                        C[kappa, p]
                                        * C[lam, q]
                                        * C[mu, r]
                                        * C[nu, s]
                                        * eris[kappa, lam, mu, nu]
                                    )
    return eris_mo


def ao2mo(C, eris):
    eris_mo = contract("ip,jq,kr,ls,ijkl", C, C, C, C, eris)
    return eris_mo


tau = t2 + contract("ub,ng->unbg", t1, t1)
g_oo = contract('')

A_2prime = contract('ikjl,ijab->klab', eris[o,o,o,o],tau)
B_2prime = contract('abcd,ijab->', eris[v,v,v,v],tau)
C_1 = contract('ijab,ia->', eris[o,o,v,v],t1_old)
C_2 = contract('ijab,ijab->', eris[o,o,v,v],t2_old)
C_2prime = contract('ijab,ijab->', eris[o,o,v,v],tau)
D_1 = contract('iajb,ia->', eris[o,v,o,v],t1_old)
D_2prime = contract('iajb,ijab->', eris[o,v,o,v],tau)
D_2primestar = contract('iajb,ijab->', eris[o,v,o,v],tau)
D_2a = contract('iajb,ijab->', eris[o,v,o,v],t2_old)
D_2b = contract('iajb,ijab->', eris[o,v,o,v],t2_old)
D_2c = contract('iajb,ijab->', eris[o,v,o,v],t2_old)
E_1star = contract('ijka,ia->', eris[o,o,o,v],t1_old)
E_1 = contract('ijka,ia->', eris[o,o,o,v],t1_old)
E_2a = contract('ijka,ijab->', eris[o,o,o,v],t2_old)
E_2b = contract('ijka,ijab->', eris[o,o,o,v],t2_old)
E_2c = contract('ijka,ijab->', eris[o,o,o,v],t2_old)
F_11 = contract('iabc,ia->', eris[o,v,v,v],t1_old)
F_12 = contract('iabc,ia->', eris[o,v,v,v],t1_old)
F_1star = contract('iabc,ia->', eris[o,v,v,v],t1_old)
F_2a = contract('iabc,ijab->', eris[o,v,v,v],t2_old)
F_2prime = contract('iabc,ijab->', eris[o,v,v,v],tau)

def t1_amps():
    o = list(range(nocc))
    v = list(range(nocc, nmo))
    t1 += -F[o, v]
    t1 += contract("ui,ib->ub", F[o, o] - np.diag(np.diag(F[o, o])), t1)
    t1 += contract("ab,ua->ub", F[v, v] - np.diag(np.diag(F[v, v])), t1)
    t1 += contract("ai,uiba->ub", F[v, o], 2 * t2 - tau.transpose(0, 1, 3, 2))
    t1 += contract('ui,ib->ib', g_oo, t1)
