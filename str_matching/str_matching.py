# coding=utf-8
import numpy as np

def rabin_karp(T,P,d,q):
    n = len(T)-1
    m = len(P)-1
    h = (d**(m-1))%q
    p = 0
    t = np.zeros((n-m+1))

    for i in range(1, m+1):
        p = (d*p + P[i])%q
        t[0] = (d*t[0] + T[i])%q

    for s in range(0, n-m+1):
        if p == t[s]:
            if (P[1:m] == T[s+1:s+m]).all():
                print ('Pattern occurs with shift %d' % s)
        if s<n-m:
            t[s+1] = (d*(t[s]-T[s+1]*h)+T[s+m+1])%q
    


fstr = np.array([0,5,6,7])
str = np.array([0,1,2,3,4,5,6,7,8])

rabin_karp(str,fstr,10,6)




