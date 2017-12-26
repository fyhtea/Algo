# coding=utf-8


def CutRod(p, n):
    if n==0:
        return 0;
    q = -1;
    for i in range(1,n+1):
        q = max(q, p[i]+CutRod(p,n-i))
    return q

p = [0,1,5,8,9,10,17,17,20,24,30]
n=6

print CutRod(p, n)
