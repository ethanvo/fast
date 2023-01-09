#!/usr/bin/env python
from pyscf import gto
import numpy as np

# Specify a molecule
mol = gto.Mole()
mol.verbose = 10
mol.atom = [
    ["O", (0.0000, 0.0000, 0.116)],
    ["H", (0.0000, 0.749, -0.463)],
    ["H", (0.0000, -0.749, -0.463)],
]
mol.basis = "cc-pvdz"
mol.build()
print(mol.ao_labels())

S = gto.getints("cint1e_ovlp_sph", mol._atm, mol._bas, mol._env)
print(np.diag(S, k=1))
