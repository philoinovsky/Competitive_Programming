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

//-------------function-starts---------------------
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size();
        int haszero = -1;
        rep(i,N) rep(j,M) if(grid[i][j] == 0) haszero = 0;
        vector<vector<pair<ll,ll>>> dp(N+1,vector<pair<ll,ll>>(M+1));
        dp[0][1] = dp[1][0] = mp(1,1);
        REP(i,1,N,1) REP(j,1,M,1) {
            ll MAX = max(dp[i+1][j].first,dp[i][j+1].first);
            ll MIN = min(dp[i+1][j].second,dp[i][j+1].second);
            dp[i+1][j+1].first = max(MAX*grid[i][j],MIN*grid[i][j]);
            dp[i+1][j+1].second = min(MAX*grid[i][j],MIN*grid[i][j]);
        }
        return (dp[N][M].first == 0) ? haszero : dp[N][M].first;
    }
};
//-------------function-ends-----------------------

int main(){
    Solution sol;
    vector<vector<int>> input = {{-1,-2,-3},{-2,-3,-3},{-3,-3,-2}};
    sol.maxProductPath(input);
    return 0;
}