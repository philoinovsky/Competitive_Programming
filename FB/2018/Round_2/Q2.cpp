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
template <typename T, size_t size> void print(const T (&array)[size], int range){ //print(array,N);
    for(size_t i = 0; i < (uint)range; ++i) std::cout << array[i] << " "; 
    cout << endl;
}
template<typename T> void print(const T& t) { //print(vector);
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, " "));
    cout << endl;
}
//global variables
const int MAXN = 2e5+10, MAXM = 1e6+10;
int N, M, A, B, P[MAXN], C[MAXM];

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    //init
    unordered_map<int,int> m;
    vector<int> degree(N,0);
    deque<int> zerodegree;
    rep(i,M) m[C[i]]++;
    vector<priority_queue<int>> v(N);
    REP(i,1,N,1){
        degree[P[i]]++;
    }
    rep(i,N){
        v[i].push(i);
        if(degree[i] == 0) zerodegree.push_back(i);
    }
    ll res = 0;
    //do things
    while(!zerodegree.empty()){
        int node = zerodegree.front();
        zerodegree.pop_front();
        int lim = min((int)v[node].size(),m[node]);
        rep(i,lim){
            res += v[node].top();
            v[node].pop();
        }
        if(P[node] != -1){
            int connectedNode = P[node];
            degree[connectedNode]--;
            if(degree[connectedNode] == 0){
                zerodegree.push_back(connectedNode);
            }
            if(v[connectedNode].size() < v[node].size()){
                swap(v[connectedNode],v[node]);
            }
            while(!v[node].empty()){
                v[connectedNode].push(v[node].top());
                v[node].pop();
            }
        }
    }
    //store results
    cout << res << endl;
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> M >> A >> B;
        P[0] = -1;
        REP(i,1,N,1) cin >> P[i];
        rep(i,M) C[i] = (1LL * A * i + B) % N;
        printf("Case #%d: ", iCase++);
        solve();
    }
    return 0;
}