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
template <typename T, size_t size> void print(const T (&array)[size], int range){ //print(array,N);
    for(size_t i = 0; i < (uint)range; ++i) std::cout << array[i] << " "; 
    cout << endl;
}
template<typename T> void print(const T& t) { //print(vector);
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, " "));
    cout << endl;
}
//global variables
#define MAXN 51
int N, M;
int H[MAXN][MAXN], HH[MAXN][MAXN];

//-------------function-starts---------------------
//-------------function-ends-----------------------

int solve(){
    int MAX = 0;
    rep(i,N) rep(j,M) MAX = max(MAX, H[i][j]);
    REP(i,1,N-1,1) REP(j,1,M-1,1) {
        HH[i][j] = MAX;
    }
    int cnt = 0;
    do {
        int n;
        cnt = 0;
        REP(i,1,N-1,1) REP(j,1,M-1,1) {
            n = max(min(min(min(HH[i][j-1],HH[i][j+1]),HH[i-1][j]),HH[i+1][j]),H[i][j]);
            if(n != HH[i][j]){
                cnt++;
                HH[i][j] = n;
            }
        }
    } while (cnt != 0);
    int res = 0;
    REP(i,1,N-1,1) REP(j,1,M-1,1) {
        res += HH[i][j] - H[i][j];
    }
    return res;
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> M;
        rep(i,N) rep(j,M) {
            cin >> H[i][j];
            HH[i][j] = H[i][j];
        }
        printf("Case #%d: %d\n", iCase++, solve());
    }
    return 0;
}