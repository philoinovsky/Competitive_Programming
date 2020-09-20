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
int N;

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    if(N < 31){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    if(N == 36) {
        cout << 5 << " " << 6 << " " << 10 << " " << 15 << endl;
    } else if (N == 40) {
        cout << 6 << " " << 9 << " " << 10 << " " << 15 << endl;
    } else if (N == 44) {
        cout << 6 << " " << 7 << " " << 10 << " " << 21 << endl;
    } else {
       cout << 6 << " " << 10 << " " << 14 << " " << N - 30 << endl;  
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N;
        solve();
    }
    return 0;
}