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
int N, M;
string S[3];
//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    //init
    //do things
    if(N == 2) {
        int odd = 0, even = 0;
        int midodd = 0, mideven = 0;
        //sliding window
        int cnt = 0;
        rep(i,2) rep(j,2){
            if(S[i][j] == '1') cnt ^= 1;
        }
        if(cnt == 1) odd = 1;
        else even = 1;
        REP(j,2,M,1){
            if(S[0][j] == '1') cnt ^= 1;
            if(S[1][j] == '1') cnt ^= 1;
            if(S[0][j-2] == '1') cnt ^= 1;
            if(S[0][j-2] == '1') cnt ^= 1;
            if(cnt == 1) midodd++;
            else mideven++;
        }
        cout << (mideven + 1) / 2;
    } else if(N == 3){
        //
    }
    //store results
}

int main(){
    cin >> N >> M;
    if(N >= 4 && M >= 4){
        cout << -1 << endl;
        return 0;
    } else if (N == 1 || M == 1){
        cout << 0 << endl;
        return 0;
    }
    rep(i,N) cin >> S[i];
    solve();
    return 0;
}