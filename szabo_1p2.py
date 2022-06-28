#!/usr/bin/env python
from math_utils import commute, acommute

A = np.array([[1, 1,  0], 
              [1, 2,  2], 
              [0, 2, -1]])

B = np.array([[ 1, -1, 1], 
              [-1,  0, 0], 
              [ 1,  0, 1]])

print(commute(A, B))
print(commute(A, B))
