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
#define MAXM 100100
int N, M, C[MAXM], D[MAXM];
map<int,vector<int>> edges;

int solve(){
    edges.clear();
    rep(i,M){
        edges[C[i]-1].push_back(D[i]-1);
        edges[D[i]-1].push_back(C[i]-1);
    }
    bool visited[MAXM] = {false};
    int NumTree = 0;
    queue<int> Q;
    rep(i,N) if(!visited[i]){
        visited[i] = true;
        Q.push(i);
        while(!Q.empty()){
            int node = Q.front();
            Q.pop();
            for(auto e: edges[node]){
                if(!visited[e]){
                    Q.push(e);
                    visited[e] = true;
                }
            }
        }
        NumTree++;
    }
    return (NumTree - 1) * 2 + (N - NumTree) ;
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> M;
        rep(i,M) cin >> C[i] >> D[i];
        printf("Case #%d: %d\n", iCase++, solve());
    }
    return 0;
}