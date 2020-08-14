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
#define MAXN 400100
#define MAXQ 100100
int N, Q;
int A1, B1, C1, M1;
int A2, B2, C2, M2;
int A3, B3, C3, M3;
int X[MAXN], Y[MAXN], Z[MAXQ], L[MAXN], R[MAXN], K[MAXQ], sufsum[2*MAXN];
ll ans;

//------------------------segment-tree-start---------------------------
class SegmentTree {
    int n;
    vector<int> tree, mark;
    inline void push_down(int p, int len){
        mark[p*2+1] += mark[p];
        mark[p*2+2] += mark[p];
        tree[p*2+1] += mark[p] * (len - len / 2);
        tree[p*2+2] += mark[p] * (len / 2);
        mark[p] = 0;
    }
    void build(const int A[]){ build(A,0,n-1,0); }
    void build(const int A[], int l, int r, int p){
        if (l == r) {
            tree[p] = A[l];
        } else {
            int mid = (l + r) / 2;
            build(A,l,mid,p*2+1);
            build(A,mid+1,r,p*2+2);
            tree[p] = tree[2*p+1] + tree[2*p+2];
        }
    }
    void update(int l, int r, int d, int p, int cl, int cr){
        if (cl > r || cr < l ) {
            return;
        } else if (cl >= l && cr <= r) {
            tree[p] += (cr - cl + 1) * d;
            if (cr > cl)
                mark[p] += d;
        } else {
            int mid = (cl + cr) / 2;
            push_down(p, cr - cl + 1);
            update(l,r,d,2*p+1,cl,mid);
            update(l,r,d,2*p+2,mid+1,cr);
            tree[p] = tree[2*p+1] + tree[2*p+2];
        }
    }
    int query(int l, int r, int p, int cl, int cr){
        if (l > r || cl > r || cr < l){
            return 0;
        } else if (cl >= l && cr <= r) {
            return tree[p];
        } else {
            int mid = (cl + cr) / 2;
            push_down(p, cr - cl + 1);
            return query(l,r,2*p+1,cl,mid) + query(l,r,2*p+2,mid+1,cr);
        }
    }
    void index(int lr, int p, int cl, int cr, vector<int> &res){
        res.push_back(p);
        if(cl != lr || cr != lr){
            int mid = (cl + cr) / 2;
            if(lr <= mid){
                index(lr,(p<<1)|1,cl,mid,res);
            } else {
                index(lr,(p<<1)+2,mid+1,cr,res);
            }
        }
    }
    vector<int> getindex(int lr){
        vector<int> res;
        if(0 >= lr && lr > n){
            return {-1};
        } else {
            index(lr,0,1,n,res);
            return res;
        }
    }
public:
    SegmentTree(){}
    SegmentTree(const int A[], int size){
        int cnt = 1;
        n = size;
        while(size > 0) { cnt++; size >>= 1; }  
        tree.resize(pow(2,cnt));
        mark.resize(pow(2,cnt));
        build(A);
    }
    SegmentTree(int size){
        int cnt = 1;
        n = size;
        while(size > 0) { cnt++; size >>= 1; }
        tree.resize(pow(2,cnt));
        mark.resize(pow(2,cnt));
    }
    // single point update: 0 <= p <= n
    void updateone(int p, int d){ update(p,p,d,0,1,n); }
    // update a range: 1 <= l,r <= n, delta be within int range
    void update(int l, int r, int d){ update(l,r,d,0,1,n); }
    // query a range: 1 <= l,r <= n
    int query(int l, int r){ return query(l,r,0,1,n); }
    void reset(){ 
        fill(tree.begin(),tree.end(),0); 
        fill(mark.begin(),mark.end(),0);
    }
};
//------------------------segment-tree-end-----------------------------

//solve
void solve(){
    ans = 0;
    set<int> s;
    map<int,int> m,mm;
    REP(i,1,N+1,1){
        s.insert(L[i]);
        s.insert(R[i]);
    }
    int idx = 1;
    repc(i,s){
        m[*i] = idx; 
        mm[idx] = *i;
        idx++;
    }
    int size = idx - 1;
    SegmentTree st(2*N);
    REP(i,1,N+1,1){
        st.update(m[L[i]],m[R[i]],1);
    }
    mm[size+1] = mm[size] + 1;
    repr(i,size+1){
        idx--;
        sufsum[idx] = st.query(i,i);
    }
    print(s);
    repc(i,m) cout << i->fi << ":" << i->se << endl;
    print(sufsum,size);
    REP(i,1,Q+1,1){
        if(K[i] > sufsum[0]) continue;
        idx = *lower_bound(sufsum, sufsum + size, K[i]);
        cout << idx << endl;
    }
}

int main(){
    int T;
    int iCase = 1;
    scanf("%d",&T);
    while(T--){
        //read params to global variables
        scanf("%d%d",&N,&Q);
        cin >> X[1] >> X[2] >> A1 >> B1 >> C1 >> M1;
        cin >> Y[1] >> Y[2] >> A2 >> B2 >> C2 >> M2;
        cin >> Z[1] >> Z[2] >> A3 >> B3 >> C3 >> M3;
        REP(i,3,N+1,1){
            X[i] = ((ll)A1*X[i-1] + (ll)B1*X[i-2] + C1) % M1;
            Y[i] = ((ll)A2*Y[i-1] + (ll)B2*Y[i-2] + C2) % M2;
        }
        REP(i,3,Q+1,1){
            Z[i] = ((ll)A3*Z[i-1] + (ll)B3*Z[i-2] + C3) % M3;
        }
        REP(i,1,N+1,1){
            L[i] = min(X[i],Y[i]) + 1;
            R[i] = max(X[i],Y[i]) + 1;
        }
        REP(i,1,Q+1,1) K[i] = Z[i] + 1;
        solve();
        printf("Case #%d: %lld\n", iCase++, ans);
    }
    return 0;
}