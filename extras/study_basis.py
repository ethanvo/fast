#!/usr/bin/env python
from pyscf import gto

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
print(mol._basis)
