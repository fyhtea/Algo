# coding=utf-8
import numpy as np


def lcs_length(x, y):
    """
    :param x: sequence X
    :param y: sequence Y
    :return:  c[i,j] is the LCS's length of Xi and Yj, b[i,j] store the entry to sub problem
    """
    m = len(x)-1
    n = len(y)-1
    c = np.zeros((m+1, n+1))  # index from 0 to m&n
    b = np.zeros((m+1, n+1))  # index from 1 to m&n

    for i in range(1, m+1):
        for j in range(1, n+1):
            if x[i] == y[j]:
                c[i, j] = c[i-1, j-1] + 1
                b[i, j] = 1
            elif c[i-1, j] >= c[i, j-1]:
                c[i, j] = c[i-1, j]
                b[i, j] = 2
            else:
                c[i, j] = c[i, j-1]
                b[i, j] = 3
    return c, b


def print_lcs(b, x, i, j):
    """
    :param b:  entry table
    :param x:  sequence X
    :param i:  X.length
    :param j:  Y.length
    :return:   LCS
    """

    if i==0 or j==0:
        return
    if b[i, j] == 1:
        print_lcs(b, x, i-1, j-1)
        print (x[i], end=" ")
    elif b[i, j] == 2:
        print_lcs(b, x, i-1, j)
    else:
        print_lcs(b, x, i, j-1)




X='0abcbdab'
Y='0bdcaba'      # index form 1 to n
i=len(X)-1
j=len(Y)-1

c,b = lcs_length(X, Y)
print ('longestlength: %d' % c[i, j])
print ('longest common sequence:', end=" ")
print_lcs(b, X, i, j)

