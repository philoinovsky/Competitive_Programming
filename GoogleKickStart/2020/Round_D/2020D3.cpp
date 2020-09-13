#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define rep(i,n) for(int i = 0; i < n; ++i)
#define repr(i,n) for(int i = n; i > -1; --i) 
#define REP(i,start,end,step) for(int i = start; i < end; i += step) 
#define REPR(i,start,end,step) for(int i = start; i > end; i += step)
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
#define MAXN 500500
int N, A, B;
int tree[MAXN];

void paint(vector<int> &cnt, int K){
    int node,numparent,connectedNode,idx,cur;
    vector<vector<int>> graph(N+1);
    vector<int> degree(N+1,0);
    vector<int> parent(N+1,-1);
    queue<int> zeroDegree;
    REP(i,2,N+1,1){
        graph[i].push_back(tree[i]);
        degree[tree[i]]++;
    }
    REP(i,1,N+1,1){
        if(degree[i] == 0){
            zeroDegree.push(i);
        }
    }
    while(!zeroDegree.empty()){
        node = zeroDegree.front();
        zeroDegree.pop();
        //find kth parent--------------------------
        if(parent[node] == -1){
            vector<int> KP(K,0);
            idx = node;
            cur = cnt[idx];
            numparent = 0;
            while(numparent < K && tree[idx] != -1){
                KP[numparent] = idx;
                idx = tree[idx];
                numparent++;
            }
            if(numparent == K){
                cnt[idx] += cur;
            }
            while(tree[idx] != -1){
                pareKP[numparent%K]
                idx++;
            }
        } else {
            cnt[parent[node]] += cnt[node];
        }
        //find kth parent---------------------------
        rep(i,(int)graph[node].size()){
            connectedNode = graph[node][i];
            degree[connectedNode]--;
            if(degree[connectedNode] == 0){
                zeroDegree.push(connectedNode);
            }
        }
    }
}

//solve
double solve(){
    //init
    vector<int> AA(N+1,1);
    vector<int> BB(N+1,1);
    //do things
    paint(AA,A);
    paint(BB,B);
    //store results
    ll SUM = 0;
    REP(i,1,N+1,1){ SUM += ((AA[i]+BB[i])*N - AA[i]*BB[i]); }
    return (double)SUM/(double)(N*N);
}

int main(){
    // std::ios::sync_with_stdio(false);
    int T, iCase(1);
    scanf("%d",&T);
    while(T--){
        //read params to global variables
        tree[1] = -1;
        scanf("%d%d%d",&N,&A,&B);
        rep(i,N-1){scanf("%d",&tree[i+2]);}
        printf("Case #%d: %.10f\n", iCase++, solve());
    }
    return 0;
}