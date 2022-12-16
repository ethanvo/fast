#!/usr/bin/env python
from cc_tools import ao2mo_explicit, ao2mo
import numpy as np

C = np.random.rand(5, 5)
eris = np.random.rand(5, 5, 5, 5)

print(ao2mo_explicit(C, eris))
print(ao2mo(C, eris))
