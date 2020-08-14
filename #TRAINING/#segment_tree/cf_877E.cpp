#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int tim = 0;
int t[maxn];
int in[maxn],ou[maxn],dfn[maxn];
vector<int> G[maxn];
void dfs(int rt, int fa){
    in[rt] = ++tim;
    dfn[tim] = rt;
    for(int i=0; i < (int)G[rt].size(); i++) {
        int to = G[rt][i];
        if(to == fa) continue;
        dfs(to,rt);
    }
    ou[rt] = tim;
}
//------------------------segment-tree-start---------------------------
class SegmentTree {
    int n;
    vector<int> tree, mark;
    inline void push_up(int p){ tree[p] = tree[2*p+1] + tree[2*p+2]; }
    inline void push_down(int p, int len){
        if(mark[p]) {
            mark[p*2+1] ^= 1;
            tree[p*2+1] = (len - len / 2) - tree[p*2+1];
            mark[p*2+2] ^= 1;
            tree[p*2+2] = (len / 2) - tree[p*2+2];            
            mark[p] = 0;
        }
    }
    void build(const int A[]){ build(A,1,n,0); }
    void build(const int A[], int l, int r, int p){
        if (l == r) {
            tree[p] = A[dfn[l]];
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
            tree[p] = (cr - cl + 1) - tree[p];
            if (cr > cl)
                mark[p] ^= 1;
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
    void updateone(int p, int d){ update(p,p,d,0,1,n); }
    void update(int l, int r, int d){ update(l,r,d,0,1,n); }
    int query(int l, int r){ return query(l,r,0,1,n); }
};
//------------------------segment-tree-end-----------------------------
 
int main() {
    int n,x;
    scanf("%d",&n);
    for(int i = 2; i <= n; i++) {
        scanf("%d",&x);
        G[x].push_back(i);
        G[i].push_back(x);
    }
    for(int i=1;i<=n;i++) scanf("%d",&t[i]);
    dfs(1,-1);//获取dfs序
    SegmentTree st(t,n);
    int q;
    scanf("%d",&q);
    while(q--) {
        char op[4];
        int v;
        scanf("%s%d",op,&v);
        if(op[0] == 'p') st.update(in[v],ou[v],1);
        else printf("%d\n",st.query(in[v],ou[v]));
    }
    return 0;
}
