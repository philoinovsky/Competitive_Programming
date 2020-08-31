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
#define MAXN 200
int N, M, A[MAXN], B[MAXN];

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    sort(A,A+N);
    reverse(A,A+N);
    int tot = 0;
    rep(i,N) {
        int MIN = 0x7fffffff;
        rep(j,M){
            MIN = min(tot | (A[i] & B[j]), MIN);
        }
        tot = MIN;
    }
    cout << tot << endl;
}

int main(){
    cin >> N >> M;
    rep(i,N) cin >> A[i];
    rep(i,M) cin >> B[i];
    solve();
    return 0;
}