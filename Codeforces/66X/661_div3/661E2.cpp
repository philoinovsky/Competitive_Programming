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
int N, V[MAXN], U[MAXN], W[MAXN], C[MAXN]; 
ll S;

//-------------function-starts---------------------
ll calc(const pair<int,int> &a){
    int weight = a.first, leaves = a.second;
    return 1LL * (weight - weight/2) * leaves;
}
struct comp{ 
    bool operator()(const pair<int,int> &a, const pair<int,int> &b){ 
        return calc(a) > calc(b);
    } 
};
//-------------function-ends-----------------------

void solve(){
    // init
    vector<vector<int>> G(N+1);
    vector<int> degree(N+1), count(N+1);
    deque<int> zerodegree;
    rep(i,N-1){
        G[V[i]].push_back(U[i]);
        G[U[i]].push_back(V[i]);
        degree[V[i]]++;
        degree[U[i]]++;
    }
    degree[1]++;
    REP(i,1,N+1,1){
        if(degree[i] == 1){ // leaf
            zerodegree.push_back(i);
            count[i] = 1;
        }
    }
    while(!zerodegree.empty()){
        int node = zerodegree.front();
        zerodegree.pop_front();
        for(auto connectedNode: G[node]){
            if(degree[connectedNode] > 1){
                count[connectedNode] += count[node];
                degree[connectedNode]--;
                if(degree[connectedNode] == 1){
                    zerodegree.push_back(connectedNode);
                }
            }
        }
    }
    multiset<pair<int,int>,comp> s1,s2;
    ll SUM1 = 0, SUM2 = 0;
    rep(i,N-1){
        int leaves = min(count[U[i]],count[V[i]]);
        if(C[i] == 1){
            s1.insert(make_pair(W[i],leaves));
            SUM1 += 1LL*leaves*W[i];            
        } else {
            s2.insert(make_pair(W[i],leaves));
            SUM2 += 1LL*leaves*W[i];   
        }
    }
    deque<ll> v1 = {SUM1}, v2 = {SUM2};
    while(SUM1){
        pair<int,int> largest = *s1.begin();
        s1.erase(s1.begin());
        SUM1 -= calc(largest);
        s1.insert(mp(largest.first/2,largest.second));
        v1.push_front(SUM1);
    }
    while(SUM2){
        pair<int,int> largest = *s2.begin();
        s2.erase(s2.begin());
        SUM2 -= calc(largest);
        s2.insert(mp(largest.first/2,largest.second));
        v2.push_front(SUM2);
    }
    int MIN = INT_MAX;
    auto v2end = v2.end();
    rep(i,(int)v1.size()){
        if(v1[i] > S) {
            break;
        } else {
            // find the largest v2[j] which is <= S - v1[i]
            auto iter = upper_bound(v2.begin(),v2.end(),S-v1[i]);
            MIN = min(MIN, (int)v1.size() - 1 - i + 2 * (int)(v2end - iter));
        }
    }
    cout << MIN << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> S;
        rep(i,N-1) cin >> V[i] >> U[i] >> W[i] >> C[i];
        solve();
    }
    return 0;
}