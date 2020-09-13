#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
#define repr(i,n) for(int i = n; i > -1; --i) 
#define REP(i,start,end,step) for(int i = start; i < end; i += step) 
#define REPR(i,start,end,step) for(int i = start; i > end; i += step)
#define lowbit(x) ((x) & (-x))
#define print(x) cout << x << endl
//global variables
#define MAXN 1000

/*
Time Complexity:
    Initialization: O(N*log(N))
    Query: O(1)
Space Complexity:
    O(N)
Offline RMQ algorithm
*/

//-----------------------Sparse-Table-starts----------------------------
int Log2[MAXN] = {0};
void ST_init(){ for(int i = 2; i <= MAXN; i++) Log2[i] = Log2[i>>1] + 1;}
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

int main(){
    ST_init();
    int A[] = {134,41,42,5,34,31,53};
    SparseTable st(A,7,min);
    print(st.query(3,6));
    return 0;
}