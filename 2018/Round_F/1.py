# -*- coding:utf-8 -*-

import math
INF = 10**5
BASE = ord('a')
END = '$'

def isPalindrome(s,l,r):
    while l<r:
        if s[l]!=s[r]:
            return False
        l += 1
        r -= 1
    return True

def solve(l,n,k):
    def P(s,l,n):
        d = len(s)
        if s[-1]=='$':
            return 1 if isPalindrome(s,0,d-2) else 0
        res = 0
        for L in range(d,n+1):
            diff = (L+1)//2-d
            if diff>=0 or isPalindrome(s,L-d,d-1):
                res += l**max(0,diff)
        return res

    if k<=n:
        return k
    if l==1:
        return 0
    t = int((n+1)//2-math.log(k,l))
    if t<0:
        return 0
    n -= (t<<1)
    k -= (t<<1)
    prefix = ""
    while True:
        res = P(prefix+'$',l,n)
        if res<=k:
            k -= res
        else:
            return len(prefix)+(t<<1)
        for i in range(l):
            c = chr(BASE + i)
            res = P(prefix+c,l,n)
            if res<=k:
                k -= res
            else:
                prefix += c
                break
        else:
            return 0

if __name__ == "__main__" :
    t = int(input())
    for round in range(1,t+1):
        l,n,k = map(int,input().split())
        print("Case #%d: %d"%(round,solve(l,n,k)))
