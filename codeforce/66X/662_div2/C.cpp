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
#define MAXN 100100
int N, A[MAXN], C[MAXN];

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    //init
    memset(C,0,sizeof(int) * MAXN);
    int MAX = 0, CC = 0;;
    rep(i,N){
        C[A[i]]++;
    }
    REP(i,1,N+1,1){
        if(C[i] > MAX) {
            MAX = C[i];
            CC = 1;
        } else if(MAX == C[i]){
            CC++;
        } 
    }
    cout << (N - CC) / (MAX - 1) - 1 << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N;
        rep(i,N) cin >> A[i];
        solve();
    }
    return 0;
}