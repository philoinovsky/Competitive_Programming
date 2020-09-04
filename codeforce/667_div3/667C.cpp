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
int N, X, Y;

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    //init
    int diff = Y - X;
    int MAX = 0;
    REPR(i,diff,0,-1){
        if(diff % i == 0){
            if(diff / i + 1 <= N){
                MAX = i;
            }
        }
    }
    rep(i, diff/MAX+1){
        cout << X + i * MAX << ' ';
    }
    N -= diff / MAX + 1;
    int diff2 = (X - 1)/ MAX;
    rep(i, min(N,(X-1)/MAX)){
        cout << X - (i + 1) * MAX << ' ';
    }
    N -= diff2;
    if(N > 0){
        REP(i,1,N+1,1){
            cout << Y + i * MAX << ' ';
        }        
    }
    //do things
    //store results
    cout << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> X >> Y;
        solve();
    }
    return 0;
}