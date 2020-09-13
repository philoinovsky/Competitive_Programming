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
bool dp[MAXN][MAXN] = {false};
string S1, S2;

void solve(){
    memset(dp,0,MAXN*MAXN*sizeof(bool));
    dp[0][0] = true;
    const int M = S1.size(), N = S2.size();
    REP(i,1,M+1,1) if(S1[i-1] == '*') dp[i][0] = dp[i-1][0];
    REP(i,1,N+1,1) if(S2[i-1] == '*') dp[0][i] = dp[0][i-1];
    REP(j,1,N+1,1) if (S2[j-1] == '*') REP(i,1,M+1,1) if(S1[i-1] == '*'){
            dp[i][j] = false;
            int B = 5;
            rep(k,min(i+1,B)) {
                dp[i][j] |= dp[i-k][j-1];
                if(S1[i-k-1] == '*') B++;
            }
            B = 5;
            rep(k,min(j+1,B)) {
                dp[i][j] |= dp[i-1][j-k];
                if(S2[j-k-1] == '*') B++;
            }
        } else {
            dp[i][j] = false;
            int B = 5;
            rep(k,min(i+1,B)) {
                dp[i][j] |= dp[i-k][j-1];
                if(S1[i-k-1] == '*') B++;
            }
    } else REP(i,1,M+1,1) if(S1[i-1] == '*'){
            dp[i][j] = false;
            int B = 5;
            rep(k,min(j+1,B)) {
                dp[i][j] |= dp[i-1][j-k];
                if(S2[j-k-1] == '*') B++;
            }
        } else {
            dp[i][j] = dp[i-1][j-1] && S1[i-1] == S2[j-1];
    }
    // cout << endl;
    // rep(i,M+1) {
    //     rep(j,N+1) cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    if(dp[M][N]) cout << "TRUE";
    else cout << "FALSE";
    cout << endl;
}

int main(){
    int T, iCase(1);
    cin >> T; cin.get();
    while(T--){
        //read params to global variables
        cin >> S1;
        cin >> S2;
        printf("Case #%d: ", iCase++);
        solve();
    }
    return 0;
}