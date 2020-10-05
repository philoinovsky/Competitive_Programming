#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
int N, X, Y;
vector<vector<int>> graph;
#define rep(i,n) for(int i = 0; i < (int)n; ++i)

//-------------dijkstra-ends-(weighted)-positive-starts----------
/*
    graph of pair<int,int> - sum of weight, node number
    condition: graph must be connected
    return a list of shortest path length from start to everynode
    time: O(VlogE+E)
*/
vector<int> dijkstra(vector<vector<pair<int,int>>> &graph, int start){
    int N = graph.size(), cntvis = 1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;
    heap.push({0,start});
    vector<bool> visited(N);
    vector<int> dist(N,INT_MAX);
    while(cntvis < N && !heap.empty()){
        auto [d,u] = heap.top();
        heap.pop();
        if(visited[u]) continue;
        visited[u] = true;
        dist[u] = d;
        cntvis++;
        for(auto [w,v]: graph[u]) if(!visited[v]) heap.push({w+dist[u],v});
    }
    return dist;
}
//-------------dijkstra-ends-(weighted)-positive-ends------------

//-------------dijkstra-ends-(weighted)-negative-starts----------
vector<int> dijkstra(vector<vector<pair<int,int>>> &graph, int start){
    vector<int> dist(N,INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;
    heap.push({0,start});
    while(!heap.empty()){
        int u = heap.top().second;
        heap.pop();
        for(auto &[w,v]: graph[u]) if(dist[v] > dist[u] + w) {
            dist[v] = dist[u] + w;
            heap.push({w,v});
        }
    }
    return dist;
}
//-------------dijkstra-ends-(weighted)-negative-ends------------

//---------------BFS-distance-unweighted-graph-starts------------
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
//---------------BFS-distance-unweighted-graph-ends--------------

//---------------------warshall-starts-----------------------
/*
    graph should be N * N which includes the adjmatrix
    time: O(N^3)
*/
void warshall(vector<vector<int>> &G){
    rep(k,N) rep(i,N) rep(j,N) G[i][j] = min(G[i][j],G[i][k]+G[k][j]);
}
//---------------------warshall-ends-------------------------

int main(){
    return 0;
}