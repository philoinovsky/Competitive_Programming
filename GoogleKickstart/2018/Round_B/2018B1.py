def solve(F, L):
    return count(L) - count(F) + 1

def count(N):
    res = 0
    L = len(str(N))
    for i,v in enumerate(str(N)):
        if i < L - 1:
            res += int(v) * (9 ** (L - 2 - i)) * 8
        else:
            for i in range(N - N % 10, N + 1):
                if i % 9 > 0:
                    res += 1
    return res

T = int(input())
for i in range(T):
    [F, L] = list(map(int,input().split()))
    print("Case #%d: %d" % (i+1, solve(F, L)))