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
int O[MAXN], H[MAXN];

//-------------function-starts---------------------
//-------------function-ends-----------------------

bool solve(){
    memset(O,0,MAXN*sizeof(int));
    memset(H,0,MAXN*sizeof(int));
    vector<vector<int>> graph(N);
    vector<int> degree(N,0);
    queue<int> zeroDegree;
    rep(i,N-1){
        graph[X[i]-1].push_back(Y[i]-1);
        graph[Y[i]-1].push_back(X[i]-1);
        degree[X[i]-1]++;
        degree[Y[i]-1]++;
    }
    degree[0]++;
    rep(i,N) if(degree[i] == 1) zeroDegree.push(i);
    while(!zeroDegree.empty()){
        int node = zeroDegree.front();
        zeroDegree.pop();
        bool condition = O[node] + H[]
        if((H[node] & 1) != (P[node] & 1) || abs(H[node]) > P[node]){
            cout << "NO" << endl; 
            return false;
        }
        for(int connectedNode: graph[node]){
            degree[connectedNode]--;
            P[connectedNode] += P[node];
            O[connectedNode] = (P[node] + H[node])/2;
            H[connectedNode] += P[node];
            if(degree[connectedNode] == 1){
                zeroDegree.push(connectedNode);
            }
        }
    }
    cout << "YES" << endl;
    return true;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> M;
        rep(i,N) cin >> P[i];
        rep(i,N) cin >> H[i];
        rep(i,N-1) cin >> X[i] >> Y[i];
        solve();
    }
    return 0;
}