#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define rep(i,n) for(int i = 0; i < n; ++i)
#define repr(i,n) for(int i = n; i > -1; --i) 
#define REP(i,start,end,step) for(int i = start; i < end; i += step) 
#define REPR(i,start,end,step) for(int i = start; i > end; i += step)
#define repc(i,c) for(auto i = c.begin(); i != c.end(); i++)
#define lowbit(x) ((x) & (-x))
typedef long long ll;
typedef unsigned long long ull;
template <typename T, size_t size> void print(const T (&array)[size], int range){ //print(array,N);
    for(size_t i = 0; i < (uint)range; ++i) std::cout << array[i] << " "; 
    cout << endl;
}
template<typename T> void print(const T& t) { //print(vector);
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, " "));
    cout << endl;
}
//global variables
#define MAXN 1010
int N, X[MAXN], Y[MAXN], res[MAXN];
bool visited[MAXN];

//solve
void solve(){
    //init
    memset(visited,0,sizeof(bool)*(N+1));
    vector<int> degree(N+1,0);
    vector<vector<int>> graph(N+1);
    deque<int> zeroDegree;
    rep(i,N){
        graph[X[i]].push_back(Y[i]); degree[X[i]]++;
        graph[Y[i]].push_back(X[i]); degree[Y[i]]++;
    }
    REP(i,1,N+1,1) if(degree[i] == 1) zeroDegree.push_back(i);
    int n;
    while(!zeroDegree.empty()){
        n = zeroDegree.size();
        rep(i,n) visited[zeroDegree[i]] = true;
        rep(i,n){
            int node = zeroDegree.front();
            zeroDegree.pop_front();
            for(int connectedNode: graph[node]) if(!visited[connectedNode]) {
                degree[connectedNode]--;
                if(degree[connectedNode] == 1) 
                    zeroDegree.push_back(connectedNode);
            }
        }
    }
    //do things
    memset(visited,0,sizeof(bool)*(N+1));
    deque<int> cycle;
    REP(i,1,N+1,1) if(degree[i] == 2) cycle.push_back(i);
    int cnt = 0;
    while(!cycle.empty()){
        n = cycle.size();
        rep(i,n) visited[cycle[i]] = true; 
        rep(i,n){
            int node = cycle.front();
            res[node] = cnt;
            cycle.pop_front();
            for(auto e: graph[node]) if(!visited[e]) cycle.push_back(e);
        }
        cnt++;
    }
}

int main(){
    // std::ios::sync_with_stdio(false);
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N;
        rep(i,N){ cin >> X[i] >> Y[i]; }
        solve();
        printf("Case #%d: ", iCase++);
        REP(i,1,N+1,1) cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}