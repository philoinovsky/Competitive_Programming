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
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, ", "));
    cout << endl;
}
//global variables
#define MAXN 200100
#define MAXQ 100100
int N, Q, A[MAXN];
char W[MAXQ];
int F[MAXQ];
int L[MAXQ];

class SegmentTree {
    long long n;
    vector<long long> tree, mark;
    inline void push_down(long long p, long long len){
        mark[p * 2] += mark[p];
        mark[p * 2 + 1] += mark[p];
        tree[p * 2] += mark[p] * (len - len / 2);
        tree[p * 2 + 1] += mark[p] * (len / 2);
        mark[p] = 0;
    }
    void build(const int A[], long long (*f)(int,int)){ build(A,1,n,1,f);}
    void build(const int A[], long long l, long long r, long long p, long long (*f)(int,int)){
        if (l == r) {
            tree[p] = (*f)(A[l],l); //modify this line to alter the construction definition
        } else {
            long long mid = (l + r) / 2;
            build(A, l, mid, p * 2, f);
            build(A, mid + 1, r, p * 2 + 1, f);
            tree[p] = tree[p * 2] + tree[p * 2 + 1];
        }
    }
public:
    SegmentTree(const int A[], int size, long long (*f)(int,int)){
        n = size;
        tree.resize(4*size);
        mark.resize(4*size);
        build(A, f);
    }
    void update(long long l, long long r, long long d){ update(l,r,d,1,1,n); }
    void update(long long l, long long r, long long d, long long p, long long cl, long long cr){
        if (cl > r || cr < l) {
            return;
        } else if (cl >= l && cr <= r) {
            tree[p] += (cr - cl + 1) * d;
            if (cr > cl)
                mark[p] += d;
        } else {
            long long mid = (cl + cr) / 2;
            push_down(p, cr - cl + 1);
            update(l, r, d, p * 2, cl, mid);
            update(l, r, d, p * 2 + 1, mid + 1, cr);
            tree[p] = tree[p * 2] + tree[p * 2 + 1];
        }
    }
    long long query(long long l, long long r){ return query(l,r,1,1,n); }
    long long query(long long l, long long r, long long p, long long cl, long long cr){
        if (cl > r || cr < l){
            return 0;
        } else if (cl >= l && cr <= r) {
            return tree[p];
        } else {
            long long mid = (cl + cr) / 2;
            push_down(p, cr - cl + 1);
            return query(l, r, p * 2, cl, mid) + query(l, r, p * 2 + 1, mid + 1, cr);
        }
    }
    void show(int nn){ for(int i = 1; i <= nn; i++) { cout << tree[i] << " "; } cout << endl; }
};

ll f1(int A, int i){ return A*pow(-1,i-1); }
ll f2(int A, int i){ return A*pow(-1,i-1)*i ; }

//solve
void solve(){
    //init
    SegmentTree T(A,N,f1);
    SegmentTree MT(A,N,f2);
    //do things
    //store results
}

int main(){
    std::ios::sync_with_stdio(false);
    int T, iCase(1);
    scanf("%d",&T);
    while(T--){
        //read params to global variables
        scanf("%d%d",&N,&Q);
        rep(i,N){scanf("%d",&A[i]);}
        rep(i,Q){scanf("%s%d%d",&W[i],&F[i],&L[i]);}
        solve();
        printf("Case #%d: \n", iCase++);
    }
    return 0;
}