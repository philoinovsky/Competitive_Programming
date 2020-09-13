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
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, " "));
    cout << endl;
}
//global variables
#define MAXN 1001000
#define MAXK 10100
const int mod = 1000000007;
int N, K, C, D, E1, E2, F;
int X[MAXN], Y[MAXN], A[MAXN];

int fastpow(int a, int b, int MOD){
    int ret(1);
    while (b) {
        if (b & 1) ret = 1LL * ret * a % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return ret;
}

int sum(int a, int b){ // a^1+a^2+...+a^b
    if (b == 1) return a;
    int ret = 1LL * sum(a, b>>1) * (1 + fastpow(a, b>>1, mod)) % mod;
    if (b & 1) {
        ret += fastpow(a,b,mod);
        if (ret >= mod) ret -= mod;
    }
    return ret;
}

//solve
int solve(){
    int ans(0), s(0);
    REP(i,1,N+1,1) {
        s += sum(i,K);
        s = (s >= mod) ? (s - mod) : s;
        ans += (1LL * A[i] * (N - i + 1) % mod * s) % mod;
        ans = (ans >= mod) ? (ans - mod) : ans;
    }
    return ans;
}

int main(){
    // std::ios::sync_with_stdio(false);
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> K >> X[1] >> Y[1] >> C >> D >> E1 >> E2 >> F;
        REP(i,2,N+1,1){ 
            X[i] = (1LL*C*X[i-1] + 1LL*D*Y[i-1] + E1) % F; 
            Y[i] = (1LL*D*X[i-1] + 1LL*C*Y[i-1] + E2) % F;
        }
        REP(i,1,N+1,1){ A[i] = (X[i] + Y[i]) % F; }
        printf("Case #%d: %d\n", iCase++, solve());
    }
    return 0;
}