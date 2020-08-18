#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 3300000, MAXBIT = 32;
int next[MAXN][2], cnt;
ll num[MAXN];
void init(){
    memset(next, -1, sizeof(next));
    memset(num, 0, sizeof(num));
    cnt = 0;
}
void insert(ll n)
{
    int cur = 0;
    for (int i = MAXBIT; i >= 0; --i)
    {
        int bit = n >> i & 1; // 求出当前位并插入
        if (next[cur][bit] == -1)
            next[cur][bit] = ++cnt;
        cur = next[cur][bit];
    }
    num[cur] = n;
}
ll find_max(ll x) // 找到与x异或最大的那个数
{
    int cur = 0;
    for (int i = MAXBIT; i >= 0; --i)
    {
        int bit = x >> i & 1;
        if (next[cur][bit ^ 1] != -1) // 优先走与当前位不同的路径
            cur = next[cur][bit ^ 1];
        else
            cur = next[cur][bit];
    }
    return num[cur];
}

int main() {
    return 0;
}