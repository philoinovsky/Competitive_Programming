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
const int MOD = 1000000007;
#define MAXN 1000100
ll N, K, W, L[MAXN], H[MAXN], AL, BL, CL, DL, AH, BH, CH, DH;

//-------------function-starts---------------------
//-------------function-ends-----------------------

ll solve(){
    ll last = L[0] + W, P = 2 * W + 2 * H[0];
    ll res = P;
    map<ll,ll> m;
    m[L[0]+W] = H[0];
    REP(i,1,N,1){
        if(L[i] > last){
            last = L[i] + W;
            P = (P + 2 * H[i] + 2 * W) % MOD;
            m.clear();
            m[L[i]+W] = H[i];
        } else {
            auto p = m.lower_bound(L[i]);
            P = (P + 2 * (L[i] + W - last)) % MOD;
            if(H[i] > p->se){
                P = (P + 2 * (H[i] - p->se)) % MOD;
            }
            auto ii = m.begin();
            for(;ii != m.end();){
                if(ii->fi <= L[i] || ii->se <= H[i]){
                    m.erase(ii++);
                } else {
                    ii++;
                }
            }
            m[L[i]+W] = H[i];
            last = L[i] + W;
        }
        res *= P;
        res %= MOD;
    }
    return res;
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> K >> W;
        rep(i,K) cin >> L[i];
        cin >> AL >> BL >> CL >> DL;
        rep(i,K) cin >> H[i];
        cin >> AH >> BH >> CH >> DH;
        REP(i,K,N,1) {
            L[i] = (AL*L[i-2] + BL*L[i-1] + CL) % DL + 1;
            H[i] = (AH*H[i-2] + BH*H[i-1] + CH) % DH + 1;
        }
        printf("Case #%d: %lld\n", iCase++, solve());
    }
    return 0;
}