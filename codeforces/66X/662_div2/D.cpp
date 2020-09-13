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
#define MAXN 2010
int N, M, up[MAXN][MAXN], down[MAXN][MAXN];
string S[MAXN];
//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    //init
    memset(up,0,sizeof(int)*MAXN*MAXN);
    memset(down,0,sizeof(int)*MAXN*MAXN);
    rep(i,N) rep(j,M) {
        up[i][j] = down[i][j] = 1;
    }
    //do things
    REPR(i,N-2,-1,-1){
        REP(j,1,M-1,1){
            if( S[i][j-1] == S[i+1][j] && 
                S[i][j+1] == S[i][j] &&
                S[i][j] == S[i+1][j] )
                up[i][j] = min(min(up[i][j-1],up[i+1][j]),up[i][j+1]) + 1;
            else
                up[i][j] = 1;
        }
    }
    REP(i,1,N,1){
        REP(j,1,M-1,1){
            if( S[i][j-1] == S[i-1][j] && 
                S[i][j+1] == S[i][j] &&
                S[i][j] == S[i-1][j] )   
                down[i][j] = min(min(down[i][j-1],down[i-1][j]),down[i][j+1]) + 1;
            else
                down[i][j] = 1;     
        }
    }
    int res = 0;
    rep(i,N) rep(j,M) {
        res += min(up[i][j],down[i][j]);
    }
    cout << res << endl;
    // cout << endl;
    // rep(i,N) {
    //     rep(j,M) cout << up[i][j] << " ";
    //     cout << endl;
    // }
    // cout << endl;
    // rep(i,N) {
    //     rep(j,M) cout << down[i][j] << " ";
    //     cout << endl;
    // }
}

int main(){
    //read params to global variables
    cin >> N >> M; cin.get();
    rep(i,N) cin >> S[i];
    solve();
    return 0;
}