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
    deque<int> Q;
    vector<bool> visited(N+1);
    Q.push_back(A);
    visited[A] = true;
    int res = 0;
    while(true){
        int size = Q.size();
        rep(_,size){
            int node = Q.front();
            Q.pop_front();
            if(node == B)
                return res;
            for(auto e: graph[node]){
                if(!visited[e]){
                    Q.push_back(e);
                    visited[e] = true;
                }
            }
        }
        res++;
    }
    return -1;
}
pair<int,int> BFS(int start){
    deque<int> Q;
    vector<bool> visited(N+1);
    Q.push_back(start);
    visited[start] = true;
    int node = -1, res = -1;
    while(!Q.empty()){
        int size = Q.size();
        rep(_,size){
            node = Q.front();
            Q.pop_front();
            for(auto e: graph[node]){
                if(!visited[e]){
                    Q.push_back(e);
                    visited[e] = true;
                }
            }
        }
        res++;
    }
    return {node,res};    
}
//-------------function-ends-----------------------

void solve(){
    vector<int> degree(N+1),cnt(N+1);
    deque<int> zerodegree;
    degree[1]++;
    REP(i,1,N+1,1){
        degree[i] = graph[i].size();
        if(degree[i] == 1){
            zerodegree.push_back(i);
        }
        cnt[i] = 1;
    }
    while(!zerodegree.empty()){
        int node = zerodegree.front();
        zerodegree.pop_front();
        for(auto connectednode: graph[node]){
            if(degree[connectednode] > 1){
                cnt[connectednode] += cnt[node];
            }
            degree[connectednode]--;
            if(degree[connectednode] == 1){
                zerodegree.push_back(connectednode);
            }
        }
    }
    int MIN = 0x7fffffff;
    vector<int> nodes;
    REP(i,1,N+1,1){
        int parent = -1, son = -1;
        for(auto e: graph[i]){
            if(cnt[e] > cnt[i]){
                parent = max(parent,N-cnt[i]);
            } else {
                son = max(son,cnt[e]);
            }
        }
        if(max(parent,son) == MIN){
            nodes.push_back(i);
        } else if (max(parent,son) < MIN) {
            MIN = min(MIN, max(parent,son));
            nodes.clear();
            nodes.push_back(i);
        }
    }
    if(nodes.size() > 1){
        pair<int,int> leaf = BFS(1);
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