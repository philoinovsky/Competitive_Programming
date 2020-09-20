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
ll A[MAXN];
int B[MAXN], N;

//-------------function-starts---------------------
vector<int> topo(vector<vector<int>> &graph, vector<int> &degree){
    deque<int> zerodegree;
    vector<int> order(N+1);
    REP(i,1,N+1,1) if(degree[i] == 0)
        zerodegree.push_back(i);
    for(int i = 1; !zerodegree.empty(); i++){
        int node = zerodegree.front();
        zerodegree.pop_front();
        order[i] = node;
        for(auto ajcnode: graph[node]) {
            if(--degree[ajcnode] == 0)
                zerodegree.push_back(ajcnode);
        }
    }
    return order;
}
void topo(vector<vector<int>> &graph){
    deque<int> degree(N+1), zerodegree;
    degree[1] = 1; // can modify
    REP(i,1,N+1,1) if((degree[i] += graph[i].size()) == 1)
        zerodegree.push_back(i);
    while(!zerodegree.empty()){
        int node = zerodegree.front();
        zerodegree.pop_front();
        for(auto ajcnode: graph[node]) if(degree[ajcnode] > 1) {
            if(--degree[ajcnode] == 1)
                zerodegree.push_back(ajcnode);
        }
    }
}
//-------------function-ends-----------------------

void solve(){
    vector<vector<int>> graph(N+1);
    REP(i,1,N+1,1){
        if(B[i] != 1){
            graph[i].push_back(B[i]);
            graph[B[i]].push_back(i);
        } 
    }
    topo(graph);
    




    vector<int> degree(N+1);
    vector<vector<int>> graph(N+1);
    REP(i,1,N+1,1) if(B[i] != -1) {
        if(A[i] > 0) {
            graph[i].push_back(B[i]);
            degree[B[i]]++;
        } else if (A[i] < 0) {
            graph[B[i]].push_back(i);
            degree[i]++;
        }
    }
    vector<int> order = topo(graph,degree);
    ll ans = 0;
    REP(i,1,N+1,1){
        int tmp = order[i];
        ans += A[tmp];
        if(B[tmp] != -1)
            A[B[tmp]] += A[tmp];
    }
    cout << ans << endl;
    REP(i,1,N+1,1)
        cout << order[i] << ' ';
    cout << endl;
}

int main(){
    cin >> N;
    rep(i,N) cin >> A[i+1];
    rep(i,N) cin >> B[i+1];
    solve();
    return 0;
}