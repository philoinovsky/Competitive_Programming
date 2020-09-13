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
const int MAXN = 1100;

//------------------------------Kruskal-starts-----------------------------------
struct edge {
    int u, v, cost;
    edge(int x,int y, int c):u(x),v(y),cost(c){}
};
bool cmp(const edge& a, const edge& b) { return a.cost < b.cost; }
class UnionFindSet {
public:
    int fa[MAXN], RANK[MAXN];
    inline void init(int n){ for (int i = 1; i <= n; ++i){ fa[i] = i; RANK[i] = 1; } }
    inline void merge(int i, int j){
        int x = find(i), y = find(j);    //find two roots first
        (RANK[x] <= RANK[y]) ? (fa[x] = y) : (fa[y] = x);
        if (RANK[x] == RANK[y] && x != y) RANK[y]++; //if same depth but root different, new root depth +1
    }
    int find(int x){ return (x == fa[x]) ? x : find(fa[x]); }
};
int Kruskal(int n, int m, vector<edge>& E) {
    UnionFindSet ufs;
    ufs.init(MAXN-1);
    int ans = 0;
    int NumEdge = 0;
    sort(E.begin(), E.end(), cmp);
    rep(i,m) {
        int faU = ufs.find(E[i].u+1), faV = ufs.find(E[i].v+1);
        if (faU != faV) {
            ufs.merge(faU,faV);
            ans += E[i].cost;
            NumEdge++;
            if (NumEdge == n - 1)
                break;
        }
    }
    return (NumEdge != n - 1) ? -1 : ans;
}
//------------------------------Kruskal-ends-------------------------------------

int main(){

}