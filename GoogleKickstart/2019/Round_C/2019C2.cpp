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
#define MAXR 310
int R, C, K, V[MAXR][MAXR];
int len[MAXR][MAXR];

//-----------------------Sparse-Table-starts----------------------------
int Log2[MAXR] = {0};
void ST_init(){ for(int i = 2; i <= MAXR; i++) Log2[i] = Log2[i>>1] + 1;}
class SparseTable{
    vector<vector<int>> table;
    int size, maxlog2;
    int const&(*cmp)(int const&, int const&);
public:
    SparseTable(const int A[], int n, int const&(*f)(int const&, int const&)):size(n),cmp(f){
        maxlog2 = Log2[size];
        table = vector<vector<int>>(size+1,vector<int>(maxlog2+1));
        for(int i = 1; i <= size; i++) table[i][0] = A[i-1];
        for (int i = 1; i <= maxlog2; i++) for (int j = 1; j + (1 << i) - 1 <= size; j++)
            table[j][i] = cmp(table[j][i-1], table[j+(1<<(i-1))][i-1]);
    }
    inline int query(int l, int r){
        int s = Log2[r-l+1];
        return cmp(table[l][s], table[r-(1<<s)+1][s]);
    }
};
//-----------------------Sparse-Table-ends--------------------------------

int solve(){
    //init
    ST_init();
    vector<SparseTable> stmax;
    vector<SparseTable> stmin;
    rep(i,R) stmax.push_back(SparseTable(V[i],C,max));
    rep(i,R) stmin.push_back(SparseTable(V[i],C,min));
    //do things
    int l, r, m;
    rep(i,R) rep(j,C){
        l = j + 1;
        r = C;
        while(l != r){
            m = ((l + r) >> 1) + 1;
            // cout << stmax[i].query(j+1,m) << " " << stmin[i].query(j+1,m) << endl;
            if(stmax[i].query(j+1,m) - stmin[i].query(j+1,m) <= K){
                l = m;
            } else {
                r = m - 1;
            }
        }
        len[i][j] = r - j;
    }
    // rep(i,R) print(len[i],C);
    //largest regtangle in a histogram
    stack<int> ss;
    int area = 0;
    rep(j,C) {
        while(!ss.empty()) ss.pop();
        ss.push(-1);
        rep(i,R+1){
            int h = len[i][j];
            while(h < len[(ss.top()+R+1)%(R+1)][j]){
                int cur_idx = ss.top();
                ss.pop();
                int cur_h = len[(cur_idx+R+1)%(R+1)][j];
                int right_boundary = i;
                int left_boundary = ss.top();
                int cur_w = right_boundary - left_boundary - 1;
                area = max(area, cur_h*cur_w);
            }
            ss.push(i);
        }
    }
    //store results
    return area;
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> R >> C >> K;
        memset(len,0,sizeof(int)*MAXR*MAXR);
        rep(i,R) rep(j,C) cin >> V[i][j];
        printf("Case #%d: %d\n", iCase++, solve());
    }
    return 0;
}