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
ll P, F, CNTS, CNTW, S, W;

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    ll tot = 0, MAX = 0;
    if(P > F) swap(P,F);
    if(S > W){
        swap(S,W);
        swap(CNTS,CNTW);
    }
    rep(i,CNTS+1){
        tot = 0;
        if(P >= S * i){
            ll rest = P - S * i;
            ll big = min(CNTW, rest/W);
            ll NS = CNTS - i, NW = CNTW - big;
            tot += i + big;
            ll small = min(NS, F/S);
            rest = F - small * S;
            big = min(NW, rest/W);
            tot += small + big;
            MAX = max(MAX, tot);
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
        cin >> P >> F >> CNTS >> CNTW >> S >> W;
        solve();
    }
    return 0;
}