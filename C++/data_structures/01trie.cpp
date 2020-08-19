#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 3300000;

//-----------------BitTrie-starts-------------------------
class BitTrie{
    vector<vector<int>> next;
    vector<long long> num;
    int cnt;
public:
    BitTrie(){}
    BitTrie(const int A[], int N){
        next = vector<vector<int>>(N,vector<int>(2,-1));
        num.resize(N);
        cnt = 0;
        #ifndef MAXBIT
            #define MAXBIT 32 
        #endif
    }
    void insert(long long n){
        int cur = 0;
        for(int i = MAXBIT; i >= 0; i--){
            int bit = n >> i & 1;
            if(next[cur][bit] == -1)
                next[cur][bit] == ++cnt;
            cnt = next[cur][bit];
        }
        num[cnt] = n;
    }
};
//-----------------BitTrie-ends-------------------------

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