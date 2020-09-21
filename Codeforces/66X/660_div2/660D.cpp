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
vector<int> topo(vector<set<int>> &graph, vector<int> &degree, vector<set<int>> &original){
    deque<int> zerodegree;
    vector<int> order(N+1);
    REP(i,1,N+1,1) if(degree[i] == 0)
        zerodegree.push_back(i);
    bool later = false;
    for(int i = 1; !zerodegree.empty(); ){
        int node = zerodegree.front();
        zerodegree.pop_front();
        if(A[node] < 0) {
            for(auto ii = graph[node].begin(); ii != graph[node].end(); ){
                int ajcnode = *ii;
                if(degree[ajcnode] >= 1 && original[node].find(ajcnode) != original[node].end()) {
                    if(--degree[ajcnode] == 0)
                        zerodegree.push_back(ajcnode);
                    degree[node] = 1;
                    graph[node].erase(ii++);
                    graph[ajcnode].insert(node);
                    later = true;
                    continue;
                }
                ii++;
            }
        }
        if(!later){
            order[i++] = node;
            for(auto ajcnode: graph[node]) {
                if(--degree[ajcnode] == 0)
                    zerodegree.push_back(ajcnode);
            }            
        }
    }
    return order;
}
//-------------function-ends-----------------------
 
void solve(){
    vector<int> degree(N+1);
    vector<set<int>> graph(N+1), original(N+1);
    REP(i,1,N+1,1) if(B[i] != -1) {
        graph[i].insert(B[i]);
        original[i].insert(B[i]);
        degree[B[i]]++;
    }
    vector<int> order = topo(graph,degree,original);
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