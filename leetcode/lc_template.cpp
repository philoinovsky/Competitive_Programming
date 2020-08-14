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
    int numberOfArithmeticSlices(vector<int>& A) {
        int N = A.size();
        vector<map<int,int>> M(N);
        int cnt = 0;
        for(int i = 1; i < N; i++) {
            for(int j = 0; j < i; j++){
                int diff = A[i] - A[j];
                if(M[j].find(diff) != M[j].end()){
                    cnt += M[j][diff];
                    M[i][diff] = M[j][diff] + 1;
                } else {
                    M[i][diff]++;
                }
            }
        }
        return cnt;
    }
};
//-------------function-ends-----------------------

int main(){
    Solution sol;
    vector<int> input = {2, 4, 6, 8, 10};
    cout << sol.numberOfArithmeticSlices(input) << endl;
    return 0;
}
