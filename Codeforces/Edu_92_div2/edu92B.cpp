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
#define MAXN 100100
int N, K, Z, A[MAXN], dp[MAXN][5];

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    K++;
    memset(dp,0,sizeof(int)*MAXN*5);
    dp[0][0] = A[0];
    REP(i,1,K,1) dp[i][0] = dp[i-1][0] + A[i];
    REP(j,1,Z+1,1) rep(i,K-2*j){
        dp[i][j] = max(dp[i+1][j-1]+A[i], dp[i][j]);
        if(i > 0){
            dp[i][j] = max(dp[i][j],dp[i-1][j]+A[i]);
        }
        // cout << i << " " << j << " " << dp[i][j] << endl;
    }
    int MAX = dp[K-1][0];
    rep(i,Z+1) {
        if(K-1-2*i >= 0){
            // cout << i << " " << K-1-2*i << endl;
            MAX = max(dp[K-1-2*i][i], MAX);
        } else {
            break;
        }
    }
    cout << MAX << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> K >> Z;
        rep(i,N) cin >> A[i];
        solve();
    }
    return 0;
}