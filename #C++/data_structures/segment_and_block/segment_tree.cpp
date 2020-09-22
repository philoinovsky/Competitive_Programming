#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
#define repr(i,n) for(int i = n; i > -1; --i) 
#define REP(i,start,end,step) for(int i = start; i < end; i += step) 
#define REPR(i,start,end,step) for(int i = start; i > end; i += step)
#define lowbit(x) ((x) & (-x))
#define print(x) cout << x << endl
//global variables

//#####################################################################
//-----------------segment-tree-min/max/gcd/lcm-start------------------
// interval: [l,r), initialization: segtree t(size+1);
struct segtree {
	int n;
	vector<int> t, ps;
	segtree(int n) : n(n) {
		t.resize(4 * n, INT_MIN);
		ps.resize(4 * n, 0);
	}
	inline void upd(int pos, int val) { return upd(0, 0, n, pos, val); }
	inline void add(int l, int r, int val) { return add(0, 0, n, l, r, val); }
	inline int get(int l, int r) { return get(0, 0, n, l, r); }
private:
    void push(int v, int l, int r) {
		if (l + 1 != r) {
			ps[v * 2 + 1] += ps[v];
			ps[v * 2 + 2] += ps[v];
		}
		t[v] += ps[v];
		ps[v] = 0;
	}
	void upd(int v, int l, int r, int pos, int val) {
		push(v, l, r);
		if (l + 1 == r) { t[v] = val; return; }
		int m = (l + r) >> 1;
		if (pos < m) upd(v * 2 + 1, l, m, pos, val);
		else upd(v * 2 + 2, m, r, pos, val);
		t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
	}
	void add(int v, int l, int r, int L, int R, int val) {
		push(v, l, r);
		if (L >= R) return;
		if (l == L && r == R) { ps[v] += val; push(v, l, r); return; }
		int m = (l + r) >> 1;
		add(v * 2 + 1, l, m, L, min(m, R), val);
		add(v * 2 + 2, m, r, max(m, L), R, val);
		t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
	}
	int get(int v, int l, int r, int L, int R) {
		push(v, l, r);
		if (L >= R) return INT_MIN;
		if (l == L && r == R) return t[v];
		int m = (l + r) >> 1;
		int r1 = get(v * 2 + 1, l, m, L, min(m, R));
		int r2 = get(v * 2 + 2, m, r, max(m, L), R);
		t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
		return max(r1, r2);
	}
};
//-----------------segment-tree-min/max/gcd/lcm-end--------------------

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
    // single point update: 1 <= p <= n
    void updateone(int p, int d){ update(p,p,d,0,1,n); }
    // update a range: 1 <= l,r <= n, delta be within int range
    void update(int l, int r, int d){ update(l,r,d,0,1,n); }
    // query a range: 1 <= l,r <= n
    int query(int l, int r){ return query(l,r,0,1,n); }
    void reset(){ 
        fill(tree.begin(),tree.end(),0); 
        fill(mark.begin(),mark.end(),0);
    }
    friend class SegmentTree2D;
};
//------------------------segment-tree-end-----------------------------

//-----------------------segment-tree-2d-start-----------------------------
class SegmentTree2D {
    int n, m;
    vector<SegmentTree> tree;
    inline void push_down(){/*not implemented*/}
    void build(){/*not implemented*/}
    // update single point in logN * logN
    void updateone(int lr1, int lr2, int d, int p, int cl1, int cr1, vector<int> &idx){
        if (cl1 > lr1 || cr1 < lr1) {
            return;
        } else if (cl1 == lr1 && cr1 == lr1) {
            for(int e:idx) tree[p].tree[e] += d;
        } else {
            int mid1 = (cl1 + cr1) / 2;
            // pushdown
            updateone(lr1,lr2,d,(p<<1)|1,cl1,mid1,idx);
            updateone(lr1,lr2,d,(p<<1)+2,mid1+1,cr1,idx);
            for(int e:idx) tree[p].tree[e] = tree[(p<<1)|1].tree[e] + tree[(p<<1)+2].tree[e];
        }
    }
    void update(int l1, int r1, int l2, int r2, int d, int p, int cl1, int cr1){
        if (cl1 > r1 || cr1 < l1) {
            return;
        } else if (cl1 >= l1 && cr1 <= r1) {
            tree[p].update(l2,r2,d);
            // if {...} add mark, not implemented;
        } else {
            int mid1 = (cl1 + cr1) / 2;
            // pushdown
            update(l1,r1,l2,r2,d,(p<<1)|1,cl1,mid1);
            update(l1,r1,l2,r2,d,(p<<1)+2,mid1+1,cr1);
            int dd = tree[(p<<1)|1].query(l2,r2) + tree[(p<<1)+2].query(l2,r2) - tree[p].query(l2,r2);
            tree[p].update(l2,r2,dd);
        }
    }
    int query(int l1, int r1, int l2, int r2, int p, int cl1, int cr1){
        if (cl1 > r1 || cr1 < l1) {
            return 0;
        } else if (cl1 >= l1 && cr1 <= r1) {
            return tree[p].query(l2,r2);	
        } else {
            int mid1 = (cl1 + cr1) / 2;
            // push down not implemented
            return
            query(l1,r1,l2,r2,(p<<1)|1,cl1,mid1) +
            query(l1,r1,l2,r2,(p<<1)+2,mid1+1,cr1);
        }
    }
public:
    SegmentTree2D(){}
    SegmentTree2D(const int A[], int size){
        // not implemented
    }
    SegmentTree2D(int nn, int mm):n(nn),m(mm){
        int cntn = 1, cntm = 1;
        while(nn > 0){ cntn++; nn >>= 1; }
        while(mm > 0){ cntm++; mm >>= 1; }
        tree = vector<SegmentTree>(pow(2,cntn),SegmentTree(pow(2,cntm)));
        // mark.resize(4*m*n);
    }
    void updateone(int lr1, int lr2, int d) {
        vector<int> idx = tree[0].getindex(lr2);
        updateone(lr1,lr2,d,0,1,n,idx);
    }
    void update(int l1, int r1, int l2, int r2, int d){ update(l1,r1,l2,r2,d,0,1,n); }
    int query(int l1, int r1, int l2, int r2){ return query(l1,r1,l2,r2,0,1,n); }
    void reset(){ 
        for(vector<SegmentTree>::iterator i = tree.begin(); i != tree.end(); i++){
            fill(i->tree.begin(),i->tree.end(),0);
        }
    }
};
//-----------------------segment-tree-2d-end-------------------------------

//-----------------------matrix-tree-start-----------------------------
class MatrixTree {
    int n, m;
    vector<int> tree, mark;
    inline void push_down(int p, int len){
        //not implemented
    }
    void build(const int A[]) { build(A,1,n,1); }
    void build(const int A[], int l, int r, int p){
        // not implemented
    }
    //  update from (l1,l2) to (r1,r2)
    void update(int l1, int r1, int l2, int r2, int d, 
                int p, int cl1, int cr1, int cl2, int cr2){
        if (cl1 > r1 || cr1 < l1 || cl2 > r2 || cr2 < l2) {
            return;
        } else if (cl1 >= l1 && cr1 <= r1 && cl2 >= l2 && cr2 <= r2) {
            tree[p] += (cr1 - cl1 + 1) * (cr2 - cl2 + 1) * d;
            // if {...} add mark, not implemented;
        } else {
            int mid1 = (cl1 + cr1) / 2, mid2 = (cl2 + cr2) / 2;
            // pushdown
            update(l1,r1,l2,r2,d,(p<<2)|1,cl1,mid1,cl2,mid2); //left upper
            update(l1,r1,l2,r2,d,(p<<2)|2,mid1+1,cr1,cl2,mid2); //left lower
            update(l1,r1,l2,r2,d,(p<<2)|3,cl1,mid1,mid2+1,cr2); //right upper
            update(l1,r1,l2,r2,d,(p<<2)+4,mid1+1,cr1,mid2+1,cr2); //right lower
            tree[p] = tree[(p<<2)|1] + tree[(p<<2)|2] + tree[(p<<2)|3] + tree[(p<<2)+4];
        }
    }
    int query(int l1, int r1, int l2, int r2, int p, 
                    int cl1, int cr1, int cl2, int cr2){
        if (l1 > r1 || l2 > r2 || cl1 > r1 || cr1 < l1 || cl2 > r2 || cr2 < l2) {
            return 0;
        } else if (cl1 >= l1 && cr1 <= r1 && cl2 >= l2 && cr2 <= r2) {
            return tree[p];	
        } else {
            int mid1 = (cl1 + cr1) / 2, mid2 = (cl2 + cr2) /2;
            // push down not implemented
            return
            query(l1,r1,l2,r2,(p<<2)|1,cl1,mid1,cl2,mid2) +
            query(l1,r1,l2,r2,(p<<2)|2,mid1+1,cr1,cl2,mid2) +
            query(l1,r1,l2,r2,(p<<2)|3,cl1,mid1,mid2+1,cr2) +
            query(l1,r1,l2,r2,(p<<2)+4,mid1+1,cr1,mid2+1,cr2);
        }
    }
public:
    MatrixTree(){}
    MatrixTree(const int A[], int size){
        // not implemented
    }
    MatrixTree(int nn, int mm):n(nn),m(mm){
        tree.resize(4*m*n);
        // mark.resize(4*m*n);
    }
    void updateone(int x, int y, int d) { update(x,x,y,y,d,0,1,n,1,m); }
    void update(int l1, int r1, int l2, int r2, int d){ update(l1,r1,l2,r2,d,0,1,n,1,m); }
    int query(int l1, int r1, int l2, int r2){ return query(l1,r1,l2,r2,0,1,n,1,m); }
};
//-----------------------matrix-tree-end-------------------------------
//#####################################################################


int main(){
    int A[3] = {1,3,5};
    SegmentTree st(A,3);
    print(st.query(1,3));
    MatrixTree mt(100,100);
    rep(i,100) rep(j,100){ mt.updateone(i+1,j+1,1); }
    mt.updateone(5,10,-5);
    print(mt.query(1,0,1,10));
    return 0;
}