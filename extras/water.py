#!/usr/bin/env python
from pyscf import gto
import json
from fileutils import dump, load

# Specify a molecule
input_dict = load("cc-pvdz.1.json")
input_dict["geometry"] = [
    ["O", (0.0000, 0.0000, 0.116)],
    ["H", (0.0000, 0.749, -0.463)],
    ["H", (0.0000, -0.749, -0.463)],
]
dump(input_dict, "water.json")
