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
#define MAXN 1000100
ll N, M, K, S, P[MAXN], Q[MAXN], AP, BP, CP, DP, AQ, BQ, CQ, DQ;

//-------------function-starts---------------------
bool ok(ll x) {
    int j = 0;
    rep(i,N) {
        if (Q[j] < P[i]) {
            if (P[i] - Q[j] > x)
                return false;
            int k = j;
            while (Q[k] < P[i]) {
                if (k == M - 1)
                    return true;
                k++;
            }
            ll cost = 0;
            if (Q[k]  < 2 * P[i] - Q[j])
                cost = 2 * Q[k] - P[i] - Q[j];
            else
                cost = P[i] - 2 * Q[j] + Q[k];
            while (cost <= x) {
                if (k == M - 1)
                    return true;
                k++;
                if (Q[k]  < 2 * P[i] - Q[j])
                    cost = 2 * Q[k] - P[i] - Q[j];
                else
                    cost = P[i] - 2 * Q[j] + Q[k];
            }
            j = k;
        } else {
            while (Q[j] - P[i] <= x) {
                if (j == M - 1)
                    return true;
                j++;
            }
        }
    }
    return (j >= M - 1);
}
//-------------function-ends-----------------------

ll solve(){
    sort(P, P + N);
    sort(Q, Q + N);
    ll ans = 0, l = 0, r = 1000000000000000000;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if(ok(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> M >> K >> S;
        rep(i,K) cin >> P[i];
        cin >> AP >> BP >> CP >> DP;
        REP(i,K,N,1) P[i] = (AP * P[i-2] + BP * P[i-1] + CP) % DP + 1;
        rep(i,K) cin >> Q[i];
        cin >> AQ >> BQ >> CQ >> DQ;
        REP(i,K,M,1) Q[i] = (AQ * Q[i-2] + BQ * Q[i-1] + CQ) % DQ + 1;
        printf("Case #%d: %lld\n", iCase++, solve());
    }
    return 0;
}