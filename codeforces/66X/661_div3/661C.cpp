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
//global variables
#define MAXN 55
int N, W[MAXN];
//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    //init
    map<int,vector<int>> m;
    rep(i,N) m[W[i]].push_back(i);
    int MAX = 0;
    REP(s,2,2*N+1,1) {
        int MAXloc = 0;
        bool vs[MAXN] = { false };
        rep(i,N) {
            if(m.find(s-W[i]) != m.end()){
                for(auto e: m[s-W[i]]){
                    if(!vs[e] && !vs[i] && e != i){
                        vs[e] = true;
                        vs[i] = true;
                        MAXloc++;
                        break;
                    }                    
                }
            }
        }
        MAX = max(MAX,MAXloc);  
    }
    cout << MAX << endl;
    //do things
    //store results
}

int main(){
    int T;
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N;
        rep(i,N) cin >> W[i];
        solve();
    }
    return 0;
}