#!/usr/bin/env python
import json
from pyscf.pbc import gto, scf
from pyscf.pbc.tools import lattice, pyscf_ase
from pyscf.gto.basis import parse_nwchem
import numpy as np
import h5py


def get_basis(formula, material_components, basis_file):
    basis = {}
    for element in material_components[formula]:
        basis[element] = parse_nwchem.load(basis_file, element)
    return basis


def get_pseudo(formula, material_components, pseudopotentials):
    pseudo = {}
    for element in material_components[formula]:
        pseudo[element] = pseudopotentials[element]
    return pseudo


material_components = {
    "c": ["C"],
    "si": ["Si"],
    "sic": ["Si", "C"],
    "bn": ["B", "N"],
    "bp": ["B", "P"],
    "aln": ["Al", "N"],
    "alp": ["Al", "P"],
    "mgo": ["Mg", "O"],
    "mgs": ["Mg", "S"],
    "lih": ["Li", "H"],
    "lif": ["Li", "F"],
    "licl": ["Li", "Cl"],
}

pseudopotentials = {
    "C": "gth-hf-rev",
    "Si": "gth-hf-rev",
    "B": "gth-hf-rev",
    "N": "gth-hf-rev",
    "P": "gth-hf-rev",
    "Al": "gth-hf-rev",
    "Mg": "gth-hf-rev-q2",
    "O": "gth-hf-rev",
    "S": "gth-hf-rev",
    "Li": "gth-hf-rev-q1",
    "H": "gth-hf-rev",
    "F": "gth-hf-rev",
    "Cl": "gth-hf-rev",
}

ccpvdz = "/burg/berkelbach/users/eav2136/builds/ccgto/basis/gth-hf-rev/cc-pvdz-lc.dat"
ccpvtz = "/burg/berkelbach/users/eav2136/builds/ccgto/basis/gth-hf-rev/cc-pvtz-lc.dat"
ccpvqz = "/burg/berkelbach/users/eav2136/builds/ccgto/basis/gth-hf-rev/cc-pvqz-lc.dat"

# Create Cell
cell = gto.Cell()
formula = "c"
ase_atom = lattice.get_ase_atom(formula)
cell.atom = pyscf_ase.ase_atoms_to_pyscf(ase_atom)
cell.a = ase_atom.cell[:]
cell.unit = "B"
cell.basis = get_basis(formula, material_components, ccpvdz)
cell.pseudo = get_pseudo(formula, material_components, pseudopotentials)
cell.verbose = 7
cell.build()

S = gto.getints("cint1e_ovlp_sph", cell._atm, cell._bas, cell._env)
V_nucl = gto.getints("cint1e_nuc_sph", cell._atm, cell._bas, cell._env)
T = gto.getints("cint1e_kin_sph", cell._atm, cell._bas, cell._env)
eris = gto.getints("cint2e_sph", cell._atm, cell._bas, cell._env)

print("OVERLAP")
print(S.shape)
print(S)
print("NUCLEAR")
print(V_nucl.shape)
print(V_nucl)
print("KINETIC")
print(T.shape)
print(T)
print("ERIS")
print(eris.shape)
print(eris)

