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
    pair<int,int> traverse(vector<vector<pair<int,int>>>& graph, int type, int N){
        vector<bool> visited(N);
        visited[0] = true;
        deque<pair<int,int>> edgepool;
        for(auto e: graph[0]){
            if(e.second == 3){
                edgepool.push_front(e);
            } else if (e.second == type) {
                edgepool.push_back(e);
            }
        }
        int rem = 0, cnt3 = 0;
        while(!edgepool.empty()){
            int node = edgepool.front().first;
            int t = edgepool.front().second;
            edgepool.pop_front();
            if(visited[node]){
                rem++;
            } else {
                if(t == 3)
                    cnt3++;
                visited[node] = true;
                for(auto e: graph[node]){
                    if(e.second == 3){
                        edgepool.push_front(e);
                    } else if (e.second == type) {
                        edgepool.push_back(e);
                    }
                }
            }
        }
        for(int i = 0; i < N; i++){
            if(!visited[i]){
                return {-1,-1};
            }
        }
        return {rem,cnt3};
    }
    int maxNumEdgesToRemove(int N, vector<vector<int>>& edges) {
        int E = edges.size();
        vector<vector<pair<int,int>>> graph(N);
        int cnt[4] = {0};
        for(int i = 0; i < E; i++){
            graph[edges[i][1]-1].push_back({edges[i][2]-1,edges[i][0]});
            graph[edges[i][2]-1].push_back({edges[i][1]-1,edges[i][0]});
            cnt[edges[i][0]]++;
        }
        pair<int,int> res1 = traverse(graph,1,N), res2 = traverse(graph,2,N);
        int rem1 = res1.first, rem2 = res2.first;
        if(rem1 == -1 || rem2 == -1){
            return -1;
        } else {
            // cout << cnt[3] << cnt[2] << cnt[1] << endl;
            return rem1 + rem2 - 3*cnt[3] - cnt[2] - cnt[1] + res1.second;
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