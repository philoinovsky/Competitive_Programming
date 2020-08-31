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
const int MAXN = 5010;
int N, A[MAXN];
int dp[MAXN][MAXN];

//-------------function-starts---------------------
int calc(int pos, int x){
    int &res = dp[pos][x];
    if(res != -1) return res;
    if(pos == N) return res = 0;
    res = 1 + calc(pos+1,N);
    res = min(res,calc(pos+1,pos)+A[pos]);
    if (x != N) {
        if (A[x] >= A[pos]){
            res = min(res, calc(pos+1,pos));
        } else {
            res = min(res, calc(pos + 1, pos) + A[pos] - a[x]);
            res = min(res, 1 + calc(pos + 1, x));
        }
    }
    return res;
}
//-------------function-ends-----------------------

void solve(){
    //init
    //do things
    //store results
}

int main(){
    cin >> N;
    rep(i,N) cin >> A[i];
    memset(dp,-1,sizeof(dp));
    cout << calc(0, N) << endl;
    return 0;
}