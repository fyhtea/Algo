# coding=utf-8
import numpy as np


def prefix_func(p):
    """
    :param p:
    :return:
    """

    m = len(p) - 1    # index starts from 1
    prefix = np.zeros((m+1), int)             # {1,2,3,...,m} -> {0,1,2,3..m-1}
    k = 0

    for q in range(2, m+1):
        while k > 0 and p[k+1] != p[q]:
            k = prefix[k]
        if p[k+1] == p[q]:
                k += 1
        prefix[q] = k

    return prefix


def kmp_matching(t, p):
    """
    :param t:
    :param p:
    :return:
    """
    m = len(p) - 1
    n = len(t) - 1
    prefix = prefix_func(p)
    q = 0

    for i in range(1, n+1):
        while q > 0 and p[q+1] != t[i]:
            q = prefix[q]
        if p[q+1] == t[i]:
            q += 1
        if q == m:
            print('Pattern occurs with shift %d' % (i-m))
            q = prefix[q]

p = '0aca'
text = '0aaaacaaaa'

kmp_matching(text, p)
