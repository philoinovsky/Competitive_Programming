#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define rep(i,n) for(int i = 0; i < (int)n; ++i)
#define repr(i,n) for(int i = (int)n; i > -1; --i) 
#define REP(i,start,end,step) for(int i = (int)start; i < (int)end; i += (int)step) 
#define REPR(i,start,end,step) for(int i = (int)start; i > (int)end; i += (int)step)
#define repc(i,c) for(auto i = c.begin(); i != c.end(); i++)
#define repcr(i,c) for(auto i = c.rbegin(); i != c.rend(); i++)
#define lowbit(x) ((x) & (-x))
typedef long long ll;
typedef unsigned long long ull;
//global variables
#define MAXN 1000100
int dp[MAXN] = {0};
const int MOD = 1000000007;
int N;
//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    dp[3] = 2;
    int bang = 6;
    REP(i,4,N+1,1){
        dp[i] = (1LL* bang * (i - 2) % MOD + 1LL* dp[i-1] * 2 % MOD) % MOD;
        bang = 1LL * bang * i % MOD;
    }
    cout << dp[N] << endl;
    //init
    //do things
    //store results
}

int main(){
    cin >> N;
    solve();
    return 0;
}