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
const int MAXN = 1e5 + 10, MAXM = 6e4 + 10, MOD = 1e9+7;
int N, M, U[MAXN], V[MAXN], P[MAXM];
ll W[MAXN];

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    //init
    vector<vector<int>> graph(N+1);
    vector<int> degree(N+1), count(N+1);
    deque<int> zerodegree;
    rep(i,N-1){
        graph[U[i]].push_back(V[i]);
        graph[V[i]].push_back(U[i]);
        degree[U[i]]++;
        degree[V[i]]++;
    }
    degree[1]++;
    REP(i,1,N+1,1){
        if(degree[i] == 1)
            zerodegree.push_back(i);
    }
    //do things
    // topo - count subtree for every nodes
    while(!zerodegree.empty()){
        int node = zerodegree.front();
        zerodegree.pop_front();
        count[node]++; // add self
        for(auto e: graph[node]){
            if(degree[e] > 1)
                count[e] += count[node];
            degree[e]--;
            if(degree[e] == 1)
                zerodegree.push_back(e);
        }
    }
    // finished topo
    vector<ll> W(N-1);
    rep(i,N-1){
        int down = min(count[U[i]],count[V[i]]);
        int up = N - down;
        W[i] = 1LL * up * down;
    }
    sort(W.begin(),W.end()); reverse(W.begin(),W.end());
    ll res = 0;
    sort(P,P+M,[](int a, int b){return a > b;});
    if(M <= N - 1){
        rep(i,M) res = (res + 1LL * P[i] * W[i]) % MOD;
        REP(i,M,N-1,1) res = (res + W[i]) % MOD;
    } else {
        ll first = 1;
        rep(i,M-(N-2)) first = (first * P[i]) % MOD;
        res = (first * W[0]) % MOD;
        REP(i,M-(N-2),M,1) res = (res + 1LL * P[i] * W[i-(M-(N-2))+1]) % MOD; 
    }
    //store results
    cout << res << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N;
        rep(i,N-1) cin >> U[i] >> V[i];
        cin >> M;
        rep(i,M) cin >> P[i];
        solve();
    }
    return 0;
}