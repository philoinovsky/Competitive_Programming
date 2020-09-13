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
#define MAXN 55
int N, A[MAXN], B[MAXN];
ll res;

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    //init
    res = 0;
    //do things
    int Amin = *min_element(A,A+N);
    int Bmin = *min_element(B,B+N);
    rep(i,N) res += max(A[i]-Amin, B[i]-Bmin);
    cout << res << endl;
    //store results
}

int main(){
    int T;
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N;
        rep(i,N) cin >> A[i];
        rep(i,N) cin >> B[i];
        solve();
    }
    return 0;
}