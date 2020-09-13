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
#define MAXN 10010
const int MOD = 1000000007;
int N, A[MAXN];
//-------------function-starts---------------------
int fastpow(int a, int b, int MOD){
    int ret(1);
    while(b){
        if (b & 1) ret = 1LL*ret*a % MOD;
        a = 1LL*a*a % MOD;
        b >>= 1;
    }
    return ret;
}
//-------------function-ends-----------------------

ll solve(){
    //init
    ll res = 0;
    //do things
    rep(i,N){
        res += 1LL * (fastpow(2,i,MOD) - fastpow(2,N-i-1,MOD)) * A[i];
        res %= MOD;
    }
    //store results
    return res;
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N;
        rep(i,N) cin >> A[i];
        printf("Case #%d: %lld\n", iCase++, solve());
    }
    return 0;
}