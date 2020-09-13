#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
#define repr(i,n) for(int i = n; i > -1; --i) 
#define REP(i,start,end,step) for(int i = start; i < end; i += step) 
#define REPR(i,start,end,step) for(int i = start; i > end; i += step)
#define lowbit(x) ((x) & (-x))
//global variables

//###############################################################################
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
    void update(int r1, int r2, int d){REP(pos,r1,(int)tree.size(),lowbit(pos))tree[pos].update(r2,1);}
    int query(int r1, int r2){int ans = 0;REPR(pos,r1,0,-lowbit(pos)) ans += tree[pos].query(r2);return ans;}
    inline int query(int l1, int r1, int l2, int r2){ return query(r1,r2) - query(l1,l2);}
};
//--------------------BIT-2D-ends-------------------------------------------------
//###############################################################################

int main(){
    BinaryIndexTree bit(20);
    bit.update(2,2);
    bit.update(3,1);
    cout << bit.query(2,3) << " " << bit.query(3) << endl;
    return 0;
}