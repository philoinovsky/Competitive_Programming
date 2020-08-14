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
const int MAXN = 1e5+10;
int N, M, S[MAXN], F[MAXN], T[MAXN], L[MAXN], R[MAXN], B[MAXN];

//------------------------segment-tree-start---------------------------
/* to modify 
    1.  push_up
    2.  push_down
    3.  Indexing in build(): if index starts from 1, it should be 
            tree[p] = A[l-1]; 
    4.  update
    5.  query
*/
class SegmentTree {
    int n;
    vector<int> tree, mark;
    inline void push_up(int p){ tree[p] = tree[2*p+1] + tree[2*p+2]; }
    inline void push_down(int p, int len){ 
        mark[p*2+1] += mark[p];
        mark[p*2+2] += mark[p];
        tree[p*2+1] += mark[p] * (len - len / 2);
        tree[p*2+2] += mark[p] * (len / 2);
        mark[p] = 0;
    }
    void build(const int A[]){ build(A,1,n,0); }
    void build(const int A[], int l, int r, int p){
        if (l == r) {
            tree[p] = A[l-1]; /* if index starts from 1, it should be A[l] */
        } else {
            int mid = (l + r) / 2;
            build(A,l,mid,p*2+1);
            build(A,mid+1,r,p*2+2);
            push_up(p);
        }
    }
    void update(int l, int r, int d, int p, int cl, int cr){
        if (cl > r || cr < l ) {
            return;
        } else if (cl >= l && cr <= r) {
            /* to modify -- starts */
            tree[p] += (cr - cl + 1) * d;
            if (cr > cl) 
                mark[p] += d;
            /* to modify -- ends */
        } else {
            int mid = (cl + cr) / 2;
            push_down(p, cr - cl + 1);
            update(l,r,d,2*p+1,cl,mid);
            update(l,r,d,2*p+2,mid+1,cr);
            push_up(p);
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
            /* to modify (the sign) */
            return query(l,r,2*p+1,cl,mid) + query(l,r,2*p+2,mid+1,cr);
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
    void updateone(int p, int d){ update(p,p,d,0,1,n); }
    void update(int l, int r, int d){ update(l,r,d,0,1,n); }
    int query(int l, int r){ return query(l,r,0,1,n); }
};
//------------------------segment-tree-end-----------------------------

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    //init
    //do things
    //store results
}

int main(){
    cin >> N >> M;
    rep(i,N) cin >> S[i] >> F[i] >> T[i];
    rep(i,M) cin >> L[i] >> R[i] >> B[i];
    solve();
    return 0;
}