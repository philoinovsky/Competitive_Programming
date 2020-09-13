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
const ll mod = 1000000007, two = 500000004, six = 166666668;
ll R, C;

ll solve(){
    const ll N = min(R,C), MED = (N * (N + 1) % mod) * two % mod;
    ll res =  N * (R * C % mod + N * R % mod * C % mod) % mod * two % mod;
    res -= N * (N + 1) % mod * (2*N + 1) % mod * six % mod * (R + C) % mod;
    res += MED * MED % mod;
    res = (res + mod) % mod;
    return res;
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> R >> C;
        printf("Case #%d: %lld\n", iCase++, solve());
    }
    return 0;
}