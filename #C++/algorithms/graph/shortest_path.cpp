#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
int N, X, Y;
vector<vector<int>> graph;
#define rep(i,n) for(int i = 0; i < (int)n; ++i)

//-------------dijkstra-starts-(weighted)-untested---------------
/*
    graph of pair<int,int> - sum of weight, node number
    condition: graph must be connected
    return a list of shortest path length from start to everynode
    time: O((N+M)logM)
*/
vector<int> dijkstra(vector<vector<pair<int,int>>> &graph, int start){
    int N = graph.size(), cntvis = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> heap;
    vector<bool> visited(N);
    vector<int> MIN(N,INT_MAX);
    for(pair<int,int> adjnode: graph[start])
        heap.push(adjnode);
    MIN[start] = 0;
    visited[start] = true;
    while(cntvis < N){
        pair<int,int> shortest = heap.top();
        int distance = shortest.first, node = shortest.second;
        if(visited[node]) continue;
        heap.pop();
        visited[node] = true;
        MIN[node] = distance;
        cntvis++;
        for(pair<int,int> edge: graph[node]){
            int edgelen = edge.first, nextnode = edge.second;
            if(!visited[nextnode])
                heap.push(make_pair(edgelen+MIN[node],nextnode));
        }   
    }
    return MIN;
}
//-------------dijkstra-ends-(weighted)-untested-----------------

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