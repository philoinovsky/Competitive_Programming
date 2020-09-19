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
    int minSubarray(vector<int>& A, int p) {
        int N = A.size();
        map<int,int> presum;
        int totsum = 0;
        rep(i,N)
            totsum = (totsum + A[i]) % p;
        if(totsum == 0)
            return 0;
        int diff = p - totsum, last = 0;
        int MIN = INT_MAX;
        rep(i,N){
            int sum = (last + A[i]) % p;
            int target = (sum + diff) % p;
            cout << target << " ";
            if(presum.find(target) != presum.end()){
                MIN = min(MIN,i-presum[target]);
            }
            presum[sum] = i;
            last = sum;
        }
        cout << endl;
        return (MIN) >= N ? -1 : MIN;
    }
};
//-------------function-ends-----------------------

int main(){
    Solution sol;
    vector<int> input = {8,32,31,18,34,20,21,13,1,27,23,22,11,15,30,4,2};
    sol.minSubarray(input,148);
    return 0;
}