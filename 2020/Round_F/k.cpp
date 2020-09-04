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
const int MAXN = 1e5+10;
vector<int> A;
int N, target;

//-------------function-starts---------------------
//-------------function-ends-----------------------

/*
Assumptions: 
    0 <= A[i] (array element value) <= 2e10
    0 < N (size of array) < 2e10
Method: Knapsack with Pruning
Time Complexity:
    Worst Case: O(target*(array length))
Language: C++
*/
vector<int> solve(vector<int> &A, int target){
    int N = A.size();
    map<int,vector<int>> m;
    m[0] = {};
    long long SUM = 0;
    for(int i = 0; i < N; i++) SUM += A[i];
    for(int i = 0; i < N; i++){
        vector<pair<int,vector<int>>> tmp;
        for(auto c = m.begin(); c != m.end();){
            if(c->first + SUM < target){
                m.erase(c++);
            } else if(c->first + A[i] <= target) {
                auto find = m.find(c->first + A[i]);
                if(find == m.end()){
                    vector<int> tmpv = c->second;
                    tmpv.push_back(i);
                    tmp.push_back(make_pair(c->first+A[i],tmpv));
                } else if (m[c->first + A[i]].size() > c->second.size() + 1) {
                    m[c->first + A[i]] = c->second;
                    m[c->first + A[i]].push_back(i);
                }
                c++;
            } else {
                break;
            }
        }
        while(!tmp.empty()){
            m[tmp.back().first] = tmp.back().second;
            tmp.pop_back();
        }
        SUM -= A[i];
    }
    return m[target];
}

int main(){
    cin >> N;
    A.resize(N);
    rep(i,N) cin >> A[i];
    cin >> target;
    print(solve(A,target));
    return 0;
}