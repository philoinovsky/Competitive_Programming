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
int N, V[MAXN], U[MAXN], W[MAXN], C[MAXN]; 
ll S;

//-------------function-starts---------------------
ll calc(const pair<int,int> &a){
    int weight = a.first, leaves = a.second;
    return 1LL * (weight - weight/2) * leaves;
}
struct comp{ 
    bool operator()(const pair<int,int> &a, const pair<int,int> &b){ 
        return calc(a) > calc(b);
    } 
};
//-------------function-ends-----------------------

void solve(){
    // init
    vector<vector<int>> G(N+1);
    vector<int> degree(N+1), count(N+1);
    deque<int> zerodegree;
    rep(i,N-1){
        G[V[i]].push_back(U[i]);
        G[U[i]].push_back(V[i]);
        degree[V[i]]++;
        degree[U[i]]++;
    }
    degree[1]++;
    REP(i,1,N+1,1){
        if(degree[i] == 1){ // leaf
            zerodegree.push_back(i);
            count[i] = 1;
        }
    }
    while(!zerodegree.empty()){
        int node = zerodegree.front();
        zerodegree.pop_front();
        for(auto connectedNode: G[node]){
            if(degree[connectedNode] > 1){
                count[connectedNode] += count[node];
                degree[connectedNode]--;
                if(degree[connectedNode] == 1){
                    zerodegree.push_back(connectedNode);
                }
            }
        }
    }
    multiset<pair<int,int>,comp> s;
    ll SUM = 0;
    rep(i,N-1){
        int leaves = min(count[U[i]],count[V[i]]);
        s.insert(make_pair(W[i],leaves));
        SUM += 1LL*leaves*W[i];
    }
    int cnt = 0;
    while(SUM > S){
        pair<int,int> largest = *s.begin();
        s.erase(s.begin());
        SUM -= calc(largest);
        s.insert(mp(largest.first/2,largest.second));
        cnt++;
    }
    cout << cnt << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> S;
        rep(i,N-1){
            cin >> V[i] >> U[i] >> W[i] >> C[i];
        }
        solve();
    }
    return 0;
}