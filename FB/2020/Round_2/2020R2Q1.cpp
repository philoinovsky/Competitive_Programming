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
const int MAXN = 1e6+10;
ll N, K, S[MAXN], AS, BS, CS, DS, X[MAXN], AX, BX, CX, DX, Y[MAXN], AY, BY, CY, DY;


//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    ll SUM = 0, LIML = 0, LIMH = 0, insufficient = 0, overflow = 0;
    rep(i,N){
        SUM += S[i];
        LIML += X[i];
        LIMH += X[i] + Y[i];
        if(X[i] > S[i]) insufficient += X[i] - S[i];
        if(S[i] > (X[i] + Y[i])) overflow += S[i] - X[i] - Y[i];
    }
    if(SUM < LIML || SUM > LIMH){
        cout << -1 << endl;
        return;
    }
    cout << max(insufficient, overflow) << endl;
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> K;
        rep(i,K) cin >> S[i];
        cin >> AS >> BS >> CS >> DS;
        REP(i,K,N,1) S[i] = (AS * S[i-2] + BS * S[i-1] + CS) % DS;
        rep(i,K) cin >> X[i];
        cin >> AX >> BX >> CX >> DX;
        REP(i,K,N,1) X[i] = (AX * X[i-2] + BX * X[i-1] + CX) % DX;
        rep(i,K) cin >> Y[i];
        cin >> AY >> BY >> CY >> DY;
        REP(i,K,N,1) Y[i] = (AY * Y[i-2] + BY * Y[i-1] + CY) % DY;
        printf("Case #%d: ", iCase++);
        solve();
    }
    return 0;
}