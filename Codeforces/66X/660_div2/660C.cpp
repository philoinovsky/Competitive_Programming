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
int N, M, P[MAXN], H[MAXN], X[MAXN], Y[MAXN];

//-------------function-starts---------------------
void topo(vector<int> &cnt, vector<int> &cnt0, vector<vector<int>> &graph){
    deque<int> degree(N+1), zerodegree;
    degree[1] = 1; // can modify
    REP(i,1,N+1,1) if((degree[i] += graph[i].size()) == 1)
        zerodegree.push_back(i);
    while(!zerodegree.empty()){
        int node = zerodegree.front();
        zerodegree.pop_front();
        for(auto ajcnode: graph[node]) if(degree[ajcnode] > 1) {
            cnt[ajcnode] += cnt[node];
            cnt0[ajcnode] += cnt0[node];
            if(--degree[ajcnode] == 1)
                zerodegree.push_back(ajcnode);
        }
    }
}
//-------------function-ends-----------------------

string solve(){
    vector<vector<int>> graph(N+1);
    vector<int> cnt(N+1), cnt0(N+1,1);
    rep(i,N-1){
        graph[X[i]].push_back(Y[i]);
        graph[Y[i]].push_back(X[i]);
    }
    REP(i,1,N+1,1) cnt[i] = P[i];
    topo(cnt,cnt0,graph);
    REP(i,1,N+1,1) {
        if(abs(H[i]) > cnt[i] || abs(H[i] - cnt[i]) % 2 != 0)
            return "NO";
    }
    REP(i,1,N+1,1){
        int son = 0;
        for(auto e: graph[i]) if(cnt0[i] > cnt0[e])
            son += H[e];
        if(son > H[i] + P[i])
            return "NO";
    }
    return "YES";
}

int main(){
    int T;
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> M;
        rep(i,N) cin >> P[i+1];
        rep(i,N) cin >> H[i+1];
        rep(i,N-1) cin >> X[i] >> Y[i];
        cout << solve() << endl;
    }
    return 0;
}