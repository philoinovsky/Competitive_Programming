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
    bool containsCycle(vector<vector<char>>& grid) {
        int N = grid.size(), M = grid[0].size();
        vector<vector<int>> degree(N,vector<int>(M,0));
        map<pair<int,int>,vector<pair<int,int>>> mm;
        queue<pair<int,int>> zeroDegree;
        for(int i = 0; i < N; i++) for(int j = 0; j < M; j++){
            char e = grid[i][j];
            if(i > 0 && grid[i-1][j] == e){ //up
                mm[make_pair(i,j)].push_back(make_pair(i-1,j));
                degree[i][j]++;
            }
            if(i < N-1 && grid[i+1][j] == e){ //down
                mm[make_pair(i,j)].push_back(make_pair(i+1,j));
                degree[i][j]++;
            }
            if(j > 0 && grid[i][j-1] == e){ //left
                mm[make_pair(i,j)].push_back(make_pair(i,j-1));
                degree[i][j]++;
            }
            if(j < M-1 && grid[i][j+1] == e){ //right
                mm[make_pair(i,j)].push_back(make_pair(i,j+1));
                degree[i][j]++;
            }
        }
        for(int i = 0; i < N; i++) for(int j = 0; j < M; j++){
            if(degree[i][j] == 1){
                zeroDegree.push(make_pair(i,j));
            }
        }
        while(!zeroDegree.empty()){
            pair<int,int> node = zeroDegree.front();
            degree[node.first][node.second]--;
            zeroDegree.pop();
            for(pair<int,int> connectedNode: mm[node]){
                degree[connectedNode.first][connectedNode.second]--;
                if(degree[connectedNode.first][connectedNode.second] == 1){
                    zeroDegree.push(connectedNode);
                }
            }
        }
        for(int i = 0; i < N; i++) for(int j = 0; j < M; j++){
            if(degree[i][j] >= 2){
                return true;
            }
        }
        return false;
    }
};
//-------------function-ends-----------------------

int main(){
    Solution sol;
    vector<vector<char>> input = {{'b'},{'b'}};
    cout << sol.containsCycle(input) << endl;
    return 0;
}