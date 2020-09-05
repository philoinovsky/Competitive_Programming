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
    int findLengthOfShortestSubarray(vector<int>& arr) {
        arr.push_back(0x7fffffff);
        int N = arr.size();
        int left = N, right = -1;
        for(int i = 1; i < N; i++){
            if(arr[i] < arr[i-1]){
                left = min(left,i);
                right = max(right,i);
            }
        }
        if(left > right){
            return 0;
        } else {
            vector<int> ordered;
            for(int i = 0; i < left; i++)
                ordered.push_back(arr[i]);
            int MIN = N;
            for(int i = right; i < N; i++){
                MIN = min(MIN,(int)(i - (upper_bound(ordered.begin(),ordered.end(),arr[i])-ordered.begin())));
            }
            return MIN;
        }
    }
};
//-------------function-ends-----------------------

int main(){
    Solution sol;
    vector<int> input = {2,2,2,1,1,1};
    sol.findLengthOfShortestSubarray(input);
    return 0;
}