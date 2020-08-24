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
int X1, Y1, Z1, X2, Y2, Z2;

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    //init
    int res = 0;
    // 2 matches 1
    int match21 = min(Z1, Y2);
    res += 2 * match21;
    Z1 -= match21;
    Y2 -= match21;
    if(Z2 == 0){
        cout << res << endl;
    } else {
        int match22 = min(Z1, Z2);
        Z1 -= match22;
        Z2 -= match22;
        if(Z2 == 0){
            cout << res << endl;
        } else {
            int match02 = min(X1,Z2);
            X1 -= match02;
            Z2 -= match02;
            if(Z2 == 0){
                cout << res << endl;
            } else {
                int match12 = min(Y1,Z2);
                Y1 -= match12;
                Z2 -= match12;
                res -= 2 * match12;
                cout << res << endl;
            }
        }
    }
    //do things
    //store results
}

int main(){
    int T;
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> X1 >> Y1 >> Z1;
        cin >> X2 >> Y2 >> Z2;
        solve();
    }
    return 0;
}