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
string S;

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    //init
    int sum = 0;
    rep(i,N) if(S[i] == '1') {
        sum++;
    }
    if(sum == 0){
        rep(i,N) cout << '0';
        cout << endl;
        return;
    }
    if(sum == N){
        rep(i,N) cout << '1';
        cout << endl;
        return;
    }
    rep(i,N-1) {
        if(S[i] == '1') sum--;
        if(S[i+N] == '1') sum++;
        if(sum == 0){
            rep(i,N) cout << '0';
            cout << endl;
            return;
        }
        if(sum == N){
            rep(i,N) cout << '1';
            cout << endl;
            return;
        }
    }
    rep(i,N) cout << '0';
    cout << endl;
    return;
    //do things
    //store results
}

int main(){
    int T;
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N; cin.get();
        cin >> S;
        solve();
    }
    return 0;
}