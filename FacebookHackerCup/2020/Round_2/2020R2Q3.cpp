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
const ll MOD = 1e9+10, MAXN = 1e6+10;
ll N, M, E, K, X[MAXN], AX, BX, CX, Y[MAXN], AY, BY, CY, I[MAXN], AI, BI, CI, W[MAXN], AW, BW, CW;

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    //init
    //do things
    //store results
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> M >> E >> K;
        rep(i,K) cin >> X[i];
        cin >> AX >> BX >> CX;
        REP(i,K,N,1) X[i] = (AX * X[i-2] + BX * X[i-1] * CX) % M;
        rep(i,K) cin >> Y[i];
        cin >> AY >> BY >> CY;
        REP(i,K,N,1) X[i] = (AY * Y[i-2] + BY * Y[i-1] * CY) % M;
        rep(i,K) cin >> I[i];
        cin >> AI >> BI >> CI;
        REP(i,K,E,1) X[i] = (AI * I[i-2] + BI * I[i-1] * CI) % (N* M + N);
        rep(i,K) cin >> W[i];
        cin >> AW >> BW >> CW;
        REP(i,K,E,1) W[i] = (AW * W[i-2] + BW * W[i-1] * CW) % (1000000000);
        printf("Case #%d: ", iCase++);
        solve();
    }
    return 0;
}