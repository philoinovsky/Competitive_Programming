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
ll N, K, L, R, LL, RR;

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    if(L > LL) {
        swap(L,LL); swap(R,RR);
    } else if (L == LL && R > RR) {
        swap(R,RR);
    }
    ll gap = (R < LL) ? LL - R : 0;
    ll total = max(R,RR) - L;
    ll rest = (gap == 0) ? max(0LL, K-N*(min(R,RR)-LL)) : K;
    ll connected = (gap == 0) ? N : 0;
    ll full = (L == LL && R == RR) ? N : 0;
    ll interval = (gap == 0) ? (min(R,RR) - LL) : 0;
    ll cnt = 0;
    while(rest > 0){
        if(connected == 0 || (connected < N && rest > gap)) { 
            // expand new
            cnt += gap;
            ll diff = min(rest, total);
            rest -= diff;
            cnt += diff;
            full += (diff == total);
            connected++;
        } else if (connected < N || full == N) {
            // expand old
            cnt += rest * 2;
            rest = 0;
        } else {
            ll diff = min((total-interval)*(N-full),rest);
            rest -= diff;
            cnt += diff;
            full += diff / (total-interval);
        }
    }
    cout << cnt << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> K;
        cin >> L >> R;
        cin >> LL >> RR;
        solve();
    }
    return 0;
}