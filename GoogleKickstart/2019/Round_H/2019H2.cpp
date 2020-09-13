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
#define MAXN 110
int N, arr[MAXN][MAXN];
pair<vector<pair<int,int>>*,vector<pair<int,int>>*>edges[MAXN][MAXN];
vector<vector<pair<int,int>>> EDGES;

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    //init
    EDGES.clear();
    rep(i,2*N-1){
        EDGES.push_back(vector<pair<int,int>>());
        int x = max(N-1-i,0), y = max(i-N+1,0);
        while(x < N && y < N){
            EDGES.back().push_back(mp(x,y));
            edges[x][y].fi = &EDGES.back();
            x++; y++;
        }

        EDGES.push_back(vector<pair<int,int>>());
        x = max(N-1-i,0), y = min(2*N-i-2,N-1);
        while(x < N && y >= 0){
            EDGES.back().push_back(mp(x,y));
            edges[x][y].se = &EDGES.back();
            x++; y--;
        }
    }
    for(auto e: EDGES){for(auto f: e) cout << f.fi << "," << f.se << " ";cout << endl;}
    //do things
    
    //store results
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N;
        char tmp;
        rep(i,N) rep(j,N) {
            cin >> tmp;
            if(tmp == '.') arr[i][j] = 0;
            else arr[i][j] = 1;
        }
        solve();
        printf("Case #%d: \n", iCase++);
    }
    return 0;
}