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
const int MAXN = 1e5+10;
ll N, A[MAXN];

//-------------function-starts---------------------
ll bruteforce(vector<ll> &A){
    ll NN = A.size();
    ll MAX = LLONG_MIN;
    rep(i,NN)REP(j,i+1,NN,1)REP(k,j+1,NN,1)REP(l,k+1,NN,1)REP(t,l+1,NN,1){
        MAX = max(MAX,A[i]*A[j]*A[k]*A[l]*A[t]);
    }
    return MAX;
}
//-------------function-ends-----------------------

void solve(){
    //init
    sort(A,A+N);
    vector<ll> input;
    if(N < 10){
        rep(i,N) input.push_back(A[i]);
    } else {
        rep(i,5) input.push_back(A[i]);
        rep(i,5) input.push_back(A[N-1-i]);
    }
    cout << bruteforce(input) << endl;
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