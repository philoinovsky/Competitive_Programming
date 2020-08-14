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
#define MAXN 110
int N, M, K;
string tree[MAXN];
int dp[MAXN][MAXN][MAXN];

//-------------function-starts---------------------
//-------------function-ends-----------------------

int solve(){
    //init
    memset(dp,0,sizeof(int)*MAXN*MAXN*MAXN);
    map<int,int> SQRT;
    rep(i,110){ SQRT[i*i] = i; }
    rep(i,N){
        dp[i][0][0] = (tree[i][0] == '#') ? 1 : 0;
        dp[i][M-1][0] = (tree[i][M-1] == '#') ? 1 : 0;
    }
    rep(j,M){
        dp[N-1][j][0] = (tree[N-1][j] == '#') ? 1 : 0;
    }
    repr(i,N-2) REP(j,1,M-1,1) if(tree[i][j] == '#') {
        int MIN = min(min(dp[i+1][j-1][0],dp[i+1][j][0]),dp[i+1][j+1][0]);
        dp[i][j][0] = (SQRT[MIN] + 1) * (SQRT[MIN] + 1);
    }
    //do things
    REP(k,1,K,1){
        rep(i,N-k) rep(j,M) if(dp[i][j][k-1] > 0) {
            REP(l,1,SQRT[dp[i][j][0]]+1,1){
                int MAX = 0;
                REP(jj,j-l+1,j+l-1+1,1){
                    MAX = max(MAX,dp[i+l][jj][k-1]);
                }
                if(MAX != 0) dp[i][j][k] = max(MAX+l*l,dp[i][j][k]);
            }
        }
    }
    //store results
    int MAX = 0;
    rep(i,N) {
        rep(j,M){
            // cout << dp[i][j][K-1] << " ";
            MAX = max(MAX,dp[i][j][K-1]);
        }
        // cout << endl;
    }
    return MAX;
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> M >> K; cin.get();
        rep(i,N) cin >> tree[i];
        printf("Case #%d: %d\n", iCase++, solve());
    }
    return 0;
}