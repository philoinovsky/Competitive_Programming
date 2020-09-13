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
int N, X, Y;
vector<vector<int>> graph;

//-------------function-starts---------------------
int distance(int A, int B){
    deque<int> Q = {A};
    vector<bool> visited(N+1);
    visited[A] = true;
    for(int res = 0, size = Q.size();(size = Q.size());res++) rep(_,size){
        int node = Q.front();
        Q.pop_front();
        if(node == B)
            return res;
        for(auto e: graph[node]) if(!visited[e]){
            Q.push_back(e);
            visited[e] = true;
        }
    }
    return -1;
}
pair<int,int> diameter(int start){
    deque<int> Q = {start};
    vector<bool> visited(N+1);
    visited[start] = true;
    int node = -1, res = -1;
    for(int size = Q.size();(size = Q.size());res++) rep(_,size){
        node = Q.front();
        Q.pop_front();
        for(auto e: graph[node]) if(!visited[e]){
            Q.push_back(e);
            visited[e] = true;
        }
    }
    return {node,res};    
}
void topo(vector<int> &cnt){
    deque<int> degree(N+1), zerodegree;
    degree[1] = 1; // can modify
    REP(i,1,N+1,1) if((degree[i] += graph[i].size()) == 1)
        zerodegree.push_back(i);
    while(!zerodegree.empty()){
        int node = zerodegree.front();
        zerodegree.pop_front();
        for(auto ajcnode: graph[node]) if(degree[ajcnode] > 1) {
            cnt[ajcnode] += cnt[node];
            if(--degree[ajcnode] == 1)
                zerodegree.push_back(ajcnode);
        }
    }
}
//-------------function-ends-----------------------

void solve(){
    vector<int> cnt(N+1,1);
    topo(cnt);
    int MIN = INT_MAX;
    vector<int> nodes;
    REP(i,1,N+1,1){
        int MAX = -1;
        for(auto e: graph[i])
            MAX = (cnt[e] > cnt[i]) ? max(MAX,N-cnt[i]) : max(MAX,cnt[e]);
        if(MAX == MIN){
            nodes.push_back(i);
        } else if (MAX < MIN) {
            MIN = min(MIN, MAX);
            nodes.clear();
            nodes.push_back(i);
        }
    }
    if(nodes.size() > 1){
        pair<int,int> leaf = diameter(1);
        int leafnode = leaf.first;
        int node1 = nodes[0], node2 = nodes[1];
        cout << leafnode << " " << graph[leafnode][0] << endl;
        if(distance(leafnode,node1) < distance(leafnode,node2)){
            cout << leafnode << " " << node2 << endl;
        } else {
            cout << leafnode << " " << node1 << endl;
        }
    } else {
        cout << X << " " << Y << endl;
        cout << X << " " << Y << endl;
    }
    return;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        //read params to global variables
        graph.clear();
        cin >> N;
        graph.resize(N+1);
        rep(i,N-1){
            cin >> X >> Y;
            graph[X].push_back(Y);
            graph[Y].push_back(X);
        }
        solve();
    }
    return 0;
}