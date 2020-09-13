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
int N, K;
string S;
//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    REP(j,K,N,1){
        int i = j - K;
        if(S[i] == S[j]){
            continue;
        } else if (S[i] == '?'){
            S[i] = S[j];
        } else if (S[j] == '?'){
            S[j] = S[i];
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    int zero = 0, one = 0, question = 0;
    rep(i,K){
        switch (S[i]) {
        case '1':
            one++;
            break;
        case '0':
            zero++;
            break;
        case '?':
            question++;
            break;
        }
    }
    if(one + question < zero || zero + question < one){
        cout << "NO" << endl;
        return;
    }
    REP(i,K,N,1){
        switch (S[i]) {
        case '1':
            one++;
            break;
        case '0':
            zero++;
            break;
        case '?':
            question++;
            break;
        }
        switch (S[i-K]) {
        case '1':
            one--;
            break;
        case '0':
            zero--;
            break;
        case '?':
            question--;
            break;
        }
        if(one + question < zero || zero + question < one){
            cout << "NO" << endl;
            return;
        }          
    }
    cout << "YES" << endl;
    return;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> K; cin.get();
        cin >> S;
        solve();
    }
    return 0;
}