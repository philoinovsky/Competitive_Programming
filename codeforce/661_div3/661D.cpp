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
#define MAXN 200100
int N;
string S;
int res[MAXN];
//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    stack<int> zero, one;
    int K = 0;
    rep(i,N) {
        if(S[i] == '0'){
            if(one.empty()){
                K++;
                zero.push(K);
                res[i] = zero.top();
            } else {
                res[i] = one.top();
                zero.push(one.top());
                one.pop();
            }
        } else {
            if(zero.empty()){
                K++;
                one.push(K);
                res[i] = one.top();
            } else {
                res[i] = zero.top();
                one.push(zero.top());
                zero.pop();
            }
        }
    }
    cout << K << endl;
    rep(i,N) cout << res[i] << " ";
    cout << endl;
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