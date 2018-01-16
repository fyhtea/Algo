# coding=utf-8

import numpy as np


def is_suffix(stra, strb):
    """
    determine whether string a is a suffix of string b
    :param stra:
    :param strb:
    :return:
    """
    a = len(stra)
    b = len(strb)
    for i in range(0, a):
        if strb[b-1-i] != stra[a-1-i]:
            return False

    return True


def transition_func(p, alphabet):
    """
    :param p: pattern to be matched, index start from 1, p[0] = 0, p='0string'
    :param alphabet:  set of input characters
    :return:
    """
    trans_func = {}  # using a dict to represent the transition function with a tuple as key

    m = len(p) - 1
    for q in range(0, m+1):
        for char in alphabet:
            k = min(m+1, q+2)
            k -= 1
            while is_suffix(p[1:k], p[1:q]+char) is not True:
                k -= 1

            trans_func[(q, char)] = k
    return trans_func


def string_automata(text, transfunc, m):
    """

    :param text:
    :param transfunc:
    :param m:
    :return:
    """

    n = len(text) - 1
    q = 0
    for i in range(1, n+1):
        q = transfunc[(q, text[i])]
        if q == m:
            print('Pattern occurs with shift %d' % (i-m))

#test

pattern = '0ababaca'

text = '0acaaaa'

alpha = 'abc'

trans = transition_func(pattern, alpha)

print(trans)

string_automata(text, trans, 3)
