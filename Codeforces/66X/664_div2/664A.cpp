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
int C[4];
//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    //init
    int cnt = 0;
    bool allpos = true;
    rep(i,3) if(C[i] <= 0) allpos = false;
    rep(i,4) {
        cnt += (C[i] & 1);
    }
    if(cnt == 4 || cnt == 0 || cnt == 1) {
        cout << "YES" << endl;
    } else if (cnt == 2) {
        cout << "NO" << endl;
    } else if (cnt == 3) {
        if(allpos) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    //do things
    //store results
}

int main(){
    int T;
    cin >> T;
    while(T--){
        //read params to global variables
        rep(i,4) cin >> C[i];
        solve();
    }
    return 0;
}