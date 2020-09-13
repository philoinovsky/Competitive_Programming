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
const int MAXN = 2e5+10;
int N, K, X[MAXN], Y[MAXN], cnt[MAXN];

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    //init
    sort(X,X+N);
    deque<pair<int,int>> pool;
    memset(cnt,0,sizeof(cnt));
    int MAX = 0, res = 0;
    rep(i,N){
        pool.push_back(mp(X[i],i));
        while(X[i] - pool.front().first > K){
            MAX = max(MAX,cnt[pool.front().second]);
            pool.pop_front();
        }
        cnt[i] = (int)pool.size();
        res = max(res,MAX+cnt[i]);
    }
    cout << res << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> K;
        rep(i,N) cin >> X[i];
        rep(i,N) cin >> Y[i];
        solve();
    }
    return 0;
}