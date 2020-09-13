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
int N, M, Y[MAXN], LX[MAXN], RX[MAXN], VX[2*MAXN], VY[2*MAXN], VV[2*MAXN];

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
            int res = query(l,r,2*p+1,cl,mid) + query(l,r,2*p+2,mid+1,cr);
            push_up(p);
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
    // single point update: 1 <= p <= n
    void updateone(int p, int d){ update(p,p,d,0,1,n); }
    // update a range: 1 <= l,r <= n, delta be within int range
    void update(int l, int r, int d){ update(l,r,d,0,1,n); }
    // query a range: 1 <= l,r <= n
    int query(int l, int r){ return query(l,r,0,1,n); }
};
//------------------------segment-tree-end-----------------------------


//-------------function-starts---------------------
int compH(int i, int j){return Y[i] < Y[j];}
int compV(int i, int j){return VY[i] < VY[j] || (VY[i] == VY[j] && VV[i] > VV[j]);}
//-------------function-ends-----------------------

void solve(){
    //init
    ll res = 1;
    vector<int> H(N), V(2*M);
    rep(i,N) {
        if(RX[i] - LX[i] == int(1e6)) res++;
        H[i] = i;
    }
    rep(i,M) {
        if(VY[2*i+1] - VY[2*i] == int(1e6)) res++;
        V[2*i] = 2*i;
        V[2*i+1] = 2*i + 1;
    }
    sort(H.begin(),H.end(),compH);
    sort(V.begin(),V.end(),compV);
    SegmentTree st(int(1e6+1));
    //do things
    for(int i = 0, j = 0; i < N; ){
        if(j >= 2*M || Y[H[i]] < VY[V[j]] || (Y[H[i]] == VY[V[j]] && VV[V[j]] == -1)){
            res += st.query(LX[H[i]]+1,RX[H[i]]+1);
            i++;
        } else {
            st.updateone(VX[V[j]]+1,VV[V[j]]);
            j++;
        }
    }
    //store results
    cout << res << endl;
}

int main(){
    cin >> N >> M;
    rep(i,N) cin >> Y[i] >> LX[i] >> RX[i];
    rep(i,M) {
        cin >> VX[2*i] >> VY[2*i] >> VY[2*i+1];
        VX[2*i+1] = VX[2*i];
        VV[2*i] = 1;
        VV[2*i+1] = -1;
    }
    solve();
    return 0;
}