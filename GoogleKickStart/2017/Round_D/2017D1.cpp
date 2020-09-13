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
#define MAXN 2010
int N, TS, TF, S[MAXN], F[MAXN], D[MAXN], dp[MAXN];

//-------------function-starts---------------------
int ceiling(int V, int S, int F){
    if(V < S) {
        return S;
    } else {
        int diff = V - S, mod = diff % F;
        if(mod > 0) return V + F - mod;
        else return V;
    }
}
//-------------function-ends-----------------------

void solve(){
    memset(dp,0,sizeof(int)*MAXN);
    int MAXIDX = 1;
    rep(i,N-1){
        dp[MAXIDX] = ceiling(dp[MAXIDX-1]+TS,S[i],F[i]) + D[i];
        if(dp[MAXIDX] > TF) dp[MAXIDX] = 0;
        REPR(j,MAXIDX-1,0,-1){
            int watch = ceiling(dp[j-1]+TS,S[i],F[i]) + D[i];
            int nowatch = ceiling(dp[j],S[i],F[i]) + D[i];
            dp[j] = min(watch,nowatch);
            if(dp[j] > TF){
                dp[j] = 0;
                MAXIDX = j;
            }
        }
        dp[0] = ceiling(dp[0],S[i],F[i]) + D[i];
        if(dp[0] > TF) {
            cout << "IMPOSSIBLE";
            return;
        }
        if(dp[MAXIDX] > 0) MAXIDX++;
    }
    int MAX = -1;
    rep(i,N) if(dp[i] > 0) MAX = i;
    if(MAX != -1) cout << MAX;
    else cout << "IMPOSSIBLE";
    return;
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> TS >> TF;
        rep(i,N-1) cin >> S[i] >> F[i] >> D[i];
        printf("Case #%d: ", iCase++);
        solve();
        cout << endl;
    }
    return 0;
}