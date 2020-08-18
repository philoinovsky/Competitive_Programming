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
    int numberOfArrays(string s, int k) {
        const int MOD = 1e9 + 7;;
        int N = s.size();
        vector<int> dp(N+1,0);
        dp[0] = 1;
        for(int i = 0; i < N; i++){
            long long num = s[i] - '0';
            int idx = i;
            while(num <= k && idx > 0){
                if(num > 0 && s[idx] != '0') {
                    dp[i+1] = (dp[i+1] + dp[idx]) % MOD;
                }
                num += 1LL * pow((long long)10,i-idx+1) * (s[idx-1] - '0');
                idx--;
            }
            if(idx == 0 && num > 0 && num <= k) dp[i+1]++;
        }
        return dp[N];
    }
};
//-------------function-ends-----------------------

int main(){
    Solution sol;
    cout << sol.numberOfArrays("48486250454844645287030712560644579294181",989) << endl;
    return 0;
}