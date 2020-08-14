#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define rep(i,n) for(int i = 0; i < n; ++i)
#define repr(i,n) for(int i = n; i > -1; --i) 
#define REP(i,start,end,step) for(int i = start; i < end; i += step) 
#define REPR(i,start,end,step) for(int i = start; i > end; i += step)
#define lowbit(x) ((x) & (-x))
typedef long long ll;
typedef unsigned long long ull;
template <typename T, size_t size>
void print(const T (&array)[size], int range){ //print(array,N);
    for(size_t i = 0; i < (uint)range; ++i) std::cout << array[i] << " ";
    cout << endl;
}
template<typename T>
void print(const T& t) { //print(vector);
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, ", "));
    cout << endl;
}
//global variables
#define MAXR 31
int R,C;
string strs[MAXR];
set<int> chars;

//solve
string solve(){
    //init
    chars.clear();
    rep(i,R) rep(j,C) chars.insert(strs[i][j]-'A');
    vector<vector<int>> graph(26);
    vector<int> degree(26);
    queue<int> zeroDegree;
    string topoOrder;
    rep(i,R-1) rep(j,C) if(strs[i+1][j] != strs[i][j]){
        graph[strs[i+1][j]-'A'].push_back(strs[i][j]-'A');
        degree[strs[i][j]-'A']++;
    }
    for(int e: chars) if(degree[e] == 0){
            zeroDegree.push(e);
            topoOrder.push_back('A'+e);
    }
    //do things
    while(!zeroDegree.empty()){
        int node = zeroDegree.front();
        zeroDegree.pop();
        rep(i,(int)graph[node].size()){
            int connectedNode = graph[node][i];
            degree[connectedNode]--;
            if(degree[connectedNode] == 0){
                zeroDegree.push(connectedNode);
                topoOrder.push_back(connectedNode+'A');
            }
        }
    }
    //store results
    if(topoOrder.size() != chars.size()){
        return "-1";
    } else {
        return topoOrder;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> R;
        rep(i,R){ cin >> strs[i]; }
        printf("Case #%d: %s\n", iCase++, solve().c_str());
    }
    return 0;
}