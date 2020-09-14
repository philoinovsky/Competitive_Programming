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
const int MAXN = 2e5+10;
int N, A[MAXN];

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    vector<vector<int>> dp(N+1,vector<int>(2,0));
    dp[0][0] = dp[0][1] = dp[1][1] = INT_MAX - 100000;
    dp[1][0] = A[0];
    if(N >= 2){
        dp[2][0] = A[0] + A[1];
        dp[2][1] = A[0];        
    }
    REP(i,3,N+1,1){
        dp[i][0] = min(dp[i-1][1]+A[i-1], dp[i-2][1]+A[i-1]+A[i-2]);
        dp[i][1] = min(dp[i-1][0],dp[i-2][0]);
    }
    cout << min(dp[N][0],dp[N][1]) << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N;
        rep(i,N) cin >> A[i];
        solve();
    }
    return 0;
}