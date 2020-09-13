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
string S;

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    S.push_back('0');
    vector<int> C;
    int cnt = 0;
    for(char e: S){
        if(e == '0') {
            if(cnt != 0){
                C.push_back(cnt);
                cnt = 0;               
            }
        } else {
            cnt++;
        }
    }
    sort(C.begin(),C.end());
    reverse(C.begin(),C.end());
    int idx = 0, tot = 0;
    for(auto e: C){
        idx ^= 1;
        if(idx & 1) tot += e;
    }
    cout << tot << endl;
}

int main(){
    int T;
    cin >> T; cin.get();
    while(T--){
        //read params to global variables
        cin >> S;
        solve();
    }
    return 0;
}