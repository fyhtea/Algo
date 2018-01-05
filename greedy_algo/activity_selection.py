# coding=utf-8
import numpy as np

s = np.array([0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12])  # index start form 1
f = np.array([0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16])





def recursive_act_selector(s, f, k, n, res):
    """
    :param s: start time array
    :param f: finish time array
    :param k: index k defines the sub problem of Sk to be solved, initial problem k is 0
    :param n: size of the original problem
    :return:
    """
    m = k + 1
    while m <= n and s[m] < f[k]:
        m += 1
    if m <= n:
        res.append(m)
        return res.append(recursive_act_selector(s, f, m, n, res))
    else:
        return


def greedy_act_selector(s, f):
    """
    :param s:
    :param f:
    :return:
    """

    n = len(s) - 1
    res =[1]
    k = 1
    for m in range(2, n+1):
        if s[m] >= f[k]:
            res.append(m)
            k = m
    return res

max_set = greedy_act_selector(s, f)
print(max_set)


max_set2 = []
recursive_act_selector(s, f, 0, 11, max_set2)
def is_none(x):
    return x!=None
set2 = list(filter(lambda x:x!=None, max_set2))
print(set2)

