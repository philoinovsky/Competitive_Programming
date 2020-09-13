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
int N, A, B, DA, DB;
vector<deque<int>> graph;

//-------------function-starts---------------------
int distance(){
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
    //init
    if(2 * DA >= DB){
        cout << "Alice" << endl;
        return;
    }
    // if can catch in first step
    if(distance() <= DA){
        cout << "Alice" << endl;
        return;
    } else {
        // if cannot catch
        pair<int,int> diameternode = BFS(A);
        int diameter = BFS(diameternode.first).second;
        // if the diameter of the tree is not larger than 2 * DA, alice
        if(diameter <= 2*DA){
            cout << "Alice" << endl;
        } else {
            // bob wins
            cout << "Bob" << endl;
        }
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        //read params to global variables
        graph.clear();
        cin >> N >> A >> B >> DA >> DB;
        graph.resize(N+1);
        rep(i,N-1){
            int U, V;
            cin >> U >> V;
            graph[U].push_back(V);
            graph[V].push_back(U);
        }
        solve();
    }
    return 0;
}