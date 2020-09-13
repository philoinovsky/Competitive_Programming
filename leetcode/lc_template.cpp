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
    bool isTransformable(string s, string t) {
        int cnts[10] = {0}, cntt[10] = {0};
        int N = s.size(), M = t.size();
        if(N != M) return false;
        rep(i,N){
            cnts[s[i]-'0']++;
            cntt[t[i]-'0']++;
        }
        rep(i,10) if(cnts[i] != cntt[i]) return false;
        vector<deque<vector<int>>> q(10);
        int cnt[10] = {0};
        repr(i,N-1){
            vector<int> tmp(10);
            REP(j,'0',s[i],1){
                tmp[j-'0'] = cnt[j-'0'];
            }
            q[s[i]-'0'].push_back(tmp);
            cnt[s[i]-'0']++;
        }
        rep(i,10) cnt[i] = 0;
        repr(i,N-1){
            REP(j,'0',t[i],1){
                if(q[t[i]-'0'].front()[j-'0'] < cnt[j-'0'])
                    return false;
            }
            q[t[i]-'0'].pop_front();
        }
        return true;
    }
};
//-------------function-ends-----------------------

int main(){
    Solution sol;
    sol.isTransformable("12345","12435");
    return 0;
}