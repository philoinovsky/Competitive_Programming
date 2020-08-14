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
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty()) return 0;
        int N = prices.size();
        vector<vector<vector<int>>> dp(N,vector<vector<int>>(2,vector<int>(k+1,0x8f000000)));
        dp[0][0][0] = 0;
        dp[0][1][0] = -prices[0];
        for(int i = 1; i < N; i++) {
            dp[i][0][0] = 0;
            dp[i][1][0] = min(dp[i-1][1][0],-prices[i]);
            for(int kk = 1; kk <= k; kk++){
                dp[i][0][kk] = max(dp[i-1][1][kk-1]+prices[i],dp[i-1][0][kk]);
                dp[i][1][kk] = max(dp[i-1][0][kk]-prices[i],dp[i-1][1][kk]);
            }
        }
        int MAX = 0x80000000;
        for(int kk = 0; kk <= k; kk++) {
            MAX = max(MAX,dp[N-1][0][kk]);
            
        }
        return MAX;
    }
};
//-------------function-ends-----------------------

int main(){
    Solution sol;
    vector<int> res = {1,2,4};
    sol.maxProfit(2,res);
    return 0;
}
