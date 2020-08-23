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
class MonotonicalStack{
    int const&(*cmp)(int const&, int const&);
public:
    deque<int> sta;
    MonotonicalStack(){}
    MonotonicalStack(int const&(*f)(int const&, int const&)):cmp(f){}
    void insert(int N, int lim){
        while(!sta.empty() && cmp(sta.back(),N) == N && sta.size() >= lim) sta.pop_front();
        sta.push_back(N);
    }
};
vector<int> merge(const vector<int> &A, const vector<int> &B){
    vector<int> res;
    return res;
}
class Solution {
public:
    vector<int> chooseN(vector<int> &nums, int N){
        MonotonicalStack ms(min);
        int size = nums.size();
        vector<int> res;
        for(int i = 0; i < size; i++){
            ms.insert(nums[i],N-(size-i-1));
        }
        while(!ms.sta.empty()){
            res.push_back(ms.sta.front());
            ms.sta.pop_front();
        }
        return res;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        if(nums1.size() > nums2.size()) nums1.swap(nums2);
        int N = nums1.size(), M = nums2.size();
        int lowerbound = max(0,k-M), upperbound = min(N,k);
        vector<int> res;
        for(int n = lowerbound; n <= upperbound; n++){
            vector<int> A = chooseN(nums1,n), B = chooseN(nums2,k-n);
            res = max(res,merge(A,B));
        }
        return 
    }
};
//-------------function-ends-----------------------

int main(){
    Solution sol;
    vector<int> n1 = {}, n2 = {};
    int k = 5;
    sol.maxNumber(n1,n2,k);
    return 0;
}