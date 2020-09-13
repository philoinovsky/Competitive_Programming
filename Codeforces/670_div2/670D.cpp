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
const int MAXN = 1e5;
ll N, Q, A[MAXN];

//-------------function-starts---------------------
ll solve(ll AA, ll BB){
    // X + Y = AA, X + BB = Y or Y + 1 or Y - 1
    // X = AA - Y, X = Y - BB
    // AA + BB == 2 * Y
    ll X, Y;
    if((AA + BB) & 1){
        BB++;
    }
    Y = (AA + BB) / 2;
    X = AA - Y;
    return max(X,Y);
}
//-------------function-ends-----------------------

void solve(){
    //init
    vector<ll> diff(N-1);
    ll inc = 0;
    rep(i,N-1){
        diff[i] = A[i+1] - A[i];
        if(diff[i] > 0) {
            inc += diff[i];
        }
    }
    cout << solve(A[0],inc) << endl;
    rep(i,Q){
        int l, r, x;
        cin >> l >> r >> x;
        l--; r--;
        if(l == 0) A[0] += x;
        if(l != 0){
            if(diff[l-1] > 0)
                inc -= diff[l-1];
            diff[l-1] += x;
            if(diff[l-1] > 0)
                inc += diff[l-1];
        }
        if(r != N-1){
            if(diff[r] > 0)
                inc -= diff[r];
            diff[r] -= x;
            if(diff[r] > 0)
                inc += diff[r];
        }
        cout << solve(A[0],inc) << endl;
    }
    //do things
    //store results
}

int main(){
    cin >> N;
    rep(i,N) cin >> A[i];
    cin >> Q;
    solve();
    return 0;
}