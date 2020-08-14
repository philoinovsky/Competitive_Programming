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
#define MAXN 17
int N, A[MAXN], B[MAXN], AA[127000][3], BB[757000][3];

//--------------------BIT-starts-------------------------------------------------
class BinaryIndexTree{
public:
    vector<int> tree;
    BinaryIndexTree(){}
    BinaryIndexTree(int n){ tree.resize(n); }
    inline void update(int i, int d){ REP(pos,i,(int)tree.size(),lowbit(pos)) tree[pos] += d; }
    inline int query(int n){ int ans = 0; REPR(pos,n,0,-lowbit(pos)) ans += tree[pos]; return ans; }
    inline int query(int a, int b){ return query(b) - query(a-1); }
};
//--------------------BIT-ends----------------------------------------------------

//--------------------BIT-2D-starts-----------------------------------------------
class BinaryIndexTree2D{
public:
    vector<BinaryIndexTree> tree;
    BinaryIndexTree2D(int n, int m){ tree = vector<BinaryIndexTree>(n,BinaryIndexTree(m)) ; }
    inline void update(int r1, int r2, int d){REP(pos,r1,(int)tree.size(),lowbit(pos))tree[pos].update(r2,1);}
    inline int query(int r1, int r2){int ans = 0;REPR(pos,r1,0,-lowbit(pos)) ans += tree[pos].query(r2);return ans;}
    inline int query(int l1, int r1, int l2, int r2){ return query(r1,r2) - query(l1,l2);}
};
//--------------------BIT-2D-ends-------------------------------------------------

void combination(vector<int> &res, ll cur, int start, int cnt0, int cnt1, int cnt2, bool repeat){
    if(start == 3*N){
        res.push_back(cur);
    } else {
        if(cnt0 < N) combination(res,cur,start+1,cnt0+1,cnt1,cnt2,repeat);
        if(cnt1 < N) combination(res,cur|(1<<(2*start)),start+1,cnt0,cnt1+1,cnt2,repeat);
        if((cnt1||repeat)&&cnt2<N) combination(res,cur|(2<<(2*start)),start+1,cnt0,cnt1,cnt2+1,repeat);
    }
}

//solve
double solve(){
    //init
    // double start = clock();
    memset(AA,0,sizeof(int)*3*127000); memset(BB,0,sizeof(int)*3*757000);
    int idx(1), sizeAA, sizeBB;
    map<int,int> m; // map the SUM to smaller number, save space for segment tree
    set<int> s; // set the SUM
    vector<int> res;
    combination(res,0,1,1,0,0,false);
    sizeAA = (int)res.size();
    rep(ri,(int)res.size()) rep(i,3*N) AA[ri][(res[ri]>>(2*i))&3] += A[i+1];
    rep(i,(int)res.size()) { s.insert(AA[i][0]); s.insert(AA[i][1]); s.insert(AA[i][2]); }
    res.clear();
    combination(res,0,0,0,0,0,true);
    sizeBB = (int)res.size();
    rep(ri,(int)res.size()) rep(i,3*N) BB[ri][(res[ri]>>2*i)&3] += B[i+1];
    rep(i,(int)res.size()) { s.insert(BB[i][0]); }
    res.clear();
    for(auto e: s){ m[e] = idx; idx++; }
    auto comp0 = [](const void *arg1, const void *arg2)->int{
        int const *lhs = static_cast<int const*>(arg1);
        int const *rhs = static_cast<int const*>(arg2);
        return lhs[0] < rhs[0] ? -1 : 1;
    };
    std::qsort(AA, sizeAA, sizeof(*AA), comp0);
    std::qsort(BB, sizeBB, sizeof(*BB), comp0);
    // cout << clock() - start << endl;
    //do things
    int case1(0), case2(0), case3(0), case4(0), bbi(0), MAX;
    BinaryIndexTree st1(s.size()+1), st2(s.size()+1);
    BinaryIndexTree2D mt4(s.size()+1,s.size()+1);
    vector<int> wins;
    rep(aai, sizeAA){
        while(AA[aai][0] > BB[bbi][0] && bbi < sizeBB){
            st1.update(m[BB[bbi][1]],1);
            st2.update(m[BB[bbi][2]],1);
            mt4.update(m[BB[bbi][1]],m[BB[bbi][2]],1);
            bbi++;
        }
        case1 = st1.query(1,m[AA[aai][1]]-1);
        case2 = st2.query(1,m[AA[aai][2]]-1);
        case4 = mt4.query(m[AA[aai][1]]-1,m[AA[aai][2]]-1);
        wins.push_back(case1 + case2 - 2 * case4);
    }
    // cout << clock() - start << endl;
    REP(i,bbi,sizeBB,1) mt4.update(m[BB[i][1]],m[BB[i][2]],1);
    rep(aai,sizeAA){
        case3 = mt4.query(m[AA[aai][1]]-1,m[AA[aai][2]]-1);
        wins[aai] += case3;
    }
    MAX = *max_element(wins.begin(),wins.end());
    // cout << clock() - start << endl;
    //store results
    return (double)MAX/(double)sizeBB;
}

int main(){
    int T;
    int iCase = 1;
    scanf("%d",&T);
    while(T--){
        //read params to global variables
        scanf("%d",&N);
        rep(i,3*N){ scanf("%d",&A[i+1]); }
        rep(i,3*N){ scanf("%d",&B[i+1]); }
        printf("Case #%d: %.9f\n", iCase++, solve());
    }
    return 0;
}