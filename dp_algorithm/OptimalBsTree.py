# coding=utf-8
import numpy as np


def optimal_bst(p, q, n):

    e = np.zeros((n+2, n+1))   # index i start from 1 to n+1, index j start from 0 to n
    w = np.zeros((n+2, n+1))      # index is same as e
    root = np.zeros((n+1, n+1))    # index i start from 1 to n

    for i in range(1, n+2):
        e[i, i-1] = q[i-1]
        w[i, i-1] = q[i-1]

    for l in range(1, n+1):
        for i in range(1, n-l+2):
            j = i+l-1
            e[i, j] = float('inf')
            w[i, j] = w[i, j-1] + p[j] + q[j]
            for r in range(i, j+1):
                t = e[i, r-1] + e[r+1, j] + w[i, j]
                if t < e[i, j]:
                    e[i, j] = t
                    root[i, j] = r
    return e, root


p = np.array([0, 0.15, 0.10, 0.05, 0.10, 0.20])     # index start from 1 to n
q = np.array([0.05, 0.10, 0.05, 0.05, 0.05, 0.10])  # index start from 0 to n

cost, root_entry = optimal_bst(p, q, 5)

print(cost)
print(root_entry)