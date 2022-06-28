#!/usr/bin/env python
import numpy as np

def commute(A, B):
    return np.dot(A, B) - np.dot(B, A)

def acommute(A, B):
    return np.dot(A, B) + np.dot(B, A)
