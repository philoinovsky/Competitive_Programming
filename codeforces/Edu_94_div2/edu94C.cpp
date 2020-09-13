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
int X;

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    int N = S.length();
    string res;
    rep(i,N){
        if(i - X < 0 && i + X >= N){
            res.push_back('0');
        } else if (i - X >= 0 && i + X >= N){
            res.push_back(S[i-X]);
        } else if (i - X < 0 && i + X < N){
            res.push_back(S[i+X]);
        } else if (i - X >= 0 && i + X < N){
            if(S[i+X] == S[i-X]){
                res.push_back(S[i+X]);
            } else {
                res.push_back('0');
            }
        }
    }
    bool flag = true;
    rep(i,N){
        if((i - X >= 0 && res[i-X] == '1')|| (i + X < N && res[i+X] == '1')){
            if(S[i] != '1'){
                flag = false;
                break;
            }
        } else {
            if(S[i] != '0'){
                flag = false;
                break;
            }
        }
    }
    if(!flag){
        cout << -1 << endl;
    } else {
        cout << res << endl;
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin.get();
        cin >> S;
        cin >> X;
        //read params to global variables
        solve();
    }
    return 0;
}