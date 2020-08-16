#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000100;

long long p[maxn], q[maxn];
int N, M, K, S;

bool ok(long long x)
{
    int j = 1;
    bool flag = false;
    for (int i = 1; i <= N; i++)
    {
        if (q[j] < p[i])
        {
            if (p[i] - q[j] > x)
                return false;
            int k = j;
            while (q[k] < p[i])
            {
                if (k == M)
                    return true;
                k++;
            }
            long long cost = 0;
            if (q[k]  < 2 * p[i] - q[j])
                cost = 2 * q[k] - p[i] - q[j];
            else
                cost = p[i] - 2 * q[j] + q[k];
            while (cost <= x)
            {
                if (k == M)
                    return true;
                k++;
                if (q[k]  < 2 * p[i] - q[j])
                    cost = 2 * q[k] - p[i] - q[j];
                else
                    cost = p[i] - 2 * q[j] + q[k];
            }
            j = k;
        }
        else
        {
            while (q[j] - p[i] <= x)
            {
                if (j == M)
                    return true;
                j++;
            }
        }
    }
    if (j < M)
        return false;
    return true;
}

int main()
{
    int t;
    scanf("%d", &t);
    int tt = 0;
    while (t--)
    {
        memset(q, 0, sizeof(q));
        memset(p, 0, sizeof(p));
        scanf("%d %d %d %d", &N, &M, &K, &S);
        for (int i = 1; i <= K; i++)
            scanf("%d", p + i);
        long long a, b, c, d;
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        for (int i = K + 1; i <= N; i++)
            p[i] = (a * p[i - 2] + b * p[i - 1] + c) % d + 1;
        for (int i = 1; i <= K; i++)
            scanf("%d", q + i);
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        for (int i = K + 1; i <= M; i++)
            q[i] = (a * q[i - 2] + b * q[i - 1] + c) % d + 1;

        sort(p + 1, p + 1 + N);
        sort(q + 1, q + 1 + M);
        long long ans = 0;
        int j = 0;
        long long l = 0, r = 1000000000000000000;
        while (l <= r)
        {
            long long mid = (l + r) / 2;
            if (ok(mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        tt++;
        printf("Case #%d: %lld\n", tt, ans);
    }
    return 0;
}