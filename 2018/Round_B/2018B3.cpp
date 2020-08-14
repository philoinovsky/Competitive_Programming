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
#define MAXN 501000
int N, A, B, C, D, E, F, M;
ll V[MAXN], H[MAXN];

inline void InsertMap(map<int,set<int>> &m,int x,int y){
    if(m.find(x) == m.end()) m[x]=set<int>(); 
    m[x].insert(y);
}

//--------------------BIT-starts-------------------------------------------------
class BIT{
public:
    vector<int> tree;
    BIT(int n){ tree.resize(n); }
    inline void update(int i, int x){ REP(pos,i,(int)tree.size(),lowbit(pos)) tree[pos] += x; }
    inline int query(int n){ int ans = 0; REPR(pos,n,0,-lowbit(pos)) ans += tree[pos]; return ans; }
    inline int query(int a, int b){ return query(b) - query(a-1); }
};
//--------------------BIT-ends----------------------------------------------------

ll solve(){
    //init
    map<int,set<int>> m;
    BIT right(M+10), left(M+10);
    REP(i,1,N+1,1) H[i]++;
    REP(i,1,N+1,1){
        InsertMap(m,V[i],H[i]);
        right.update(H[i],1);
    }
    ll res(0);
    //do things
    int rhi,rlo,lhi,llo;
    int leftcnt(0), rightcnt(N);
    for(auto e: m){
        rightcnt -= e.se.size();
        for(auto f: e.se) right.update(f,-1);
        for(auto f: e.se){
            rlo = right.query(f-1);
            rhi = rightcnt - right.query(f);
            llo = left.query(f-1);
            lhi = leftcnt - left.query(f);
            res += 1LL*rhi*llo + 1LL*lhi*rlo;
        }
        for(auto f: e.se) left.update(f,1);
        leftcnt += e.se.size();
    }
    //store results
    return res;
}

int main(){
    std::ios::sync_with_stdio(false);
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> V[1] >> H[1] >> A >> B >> C >> D >> E >> F >> M;
        REP(i,2,N+1,1){
            V[i] = (V[i-1]*A + H[i-1]*B + C) % M;
            H[i] = (V[i-1]*D + H[i-1]*E + F) % M;
        }
        ll res = solve();
        res = 1LL*N*(N-1)*(N-2)/6 - res;
        printf("Case #%d: %lld\n", iCase++, res);
    }
    return 0;
}