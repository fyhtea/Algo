import numpy as np

p = np.array([30, 35, 15, 5, 10, 20, 25])


def matrix_chain_order(p):
    n = len(p) - 1

    m = np.zeros((n, n))
    s = np.zeros((n, n), dtype=int)

    for l in range(2, n+1):                               # l:Length of subproblem
        for i in range(0, n-l+1):                         # i:start index of every subproblem
            j = i+l-1                                     # j:end index of sub
            m[i, j] = float("inf")
            for k in range(i, j):                         # k:possible split position
                q = m[i, k] + m[k+1, j] + p[i]*p[k+1]*p[j+1]
                if q < m[i, j]:
                    m[i, j] = q
                    s[i, j] = k

    return m, s


def print_optimal_parens(s, i, j):
    if i == j:
        print ('A%d' % i, end='')
    else:
        print ("(", end='')
        print_optimal_parens(s, i, s[i, j])
        print_optimal_parens(s, s[i, j]+1, j)
        print(")", end='')


m, s = matrix_chain_order(p)
#print(m)
print_optimal_parens(s, 0, 5)
print()
