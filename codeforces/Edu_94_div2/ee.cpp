#include <bits/stdc++.h>

using namespace std;

const int N = int(5e3) + 9;

int n;
int a[N];
int dp[N][N];

int calc (int pos, int x) {
    int &res = dp[pos][x];
    if (res != -1) return res;
    
    if (pos == n) return res = 0;
    res = 1 + calc(pos + 1, n);
    res = min(res, calc(pos + 1, pos) + a[pos]);
    if (x != n) {
        if (a[x] >= a[pos])
            res = min(res, calc(pos + 1, pos));
        else {
            res = min(res, calc(pos + 1, pos) + a[pos] - a[x]);
            res = min(res, 1 + calc(pos + 1, x));
        }
    }
    
    return res;
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);

    memset(dp, -1, sizeof(dp));       
    printf("%d\n", calc(0, n));
    
    return 0;
}