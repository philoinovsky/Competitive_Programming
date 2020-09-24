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
const int MAXN = 3e5+10;
int N, Q, A[MAXN], L[MAXN], R[MAXN];

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    vector<vector<ll>> dp(N,vector<ll>(2));
    dp[0][0] = A[0];
    REP(i,1,N,1){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]+A[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0]-A[i]);
    }
    cout << max(dp[N-1][0],dp[N-1][1]) << endl;
    vector<ll> base(N);
    rep(i,N) base[i] = dp[i][1];
    rep(i,Q){
        if(L[i] == R[i]) {
            cout << A[N-1] + base[N-1] << endl;
            continue;
        } else {
            swap(A[L[i]-1],A[R[i]-1]);

        }
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> Q;
        rep(i,N) cin >> A[i];
        rep(i,Q) cin >> L[i] >> R[i];
        solve();
    }
    return 0;
}