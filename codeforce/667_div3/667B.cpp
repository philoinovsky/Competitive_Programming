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
int A, B, X, Y, N;

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    //init
    if (A - X + B - Y <= N){
        cout << 1LL * X * Y << endl;
        return;
    }
    int diff = min(A-X,N);
    ll res = 1LL * (A-diff) * (B-(N-diff));
    diff = min(B-Y,N);
    res = min(res,1LL*(B-diff)*(A-(N-diff)));
    cout << res << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> A >> B >> X >> Y >> N;
        solve();
    }
    return 0;
}