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
int N, M, SX, SY;

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    cout << SX << " " << SY << endl;
    int sx = SX, sy = SY;
    while(sy != 1){
        sy--;
        cout << sx << " " << sy << endl;
    }
    sy = SY;
    while(sy != M) {
        sy++;
        cout << sx << " " << sy << endl;
    }
    bool end = true;
    while(sx != 1){
        sx--;
        if(end) {
            REPR(i,M,0,-1){
                cout << sx << " " << i << endl;
            }
        } else {
            REP(i,1,M+1,1){
                cout << sx << " " << i << endl;
            }
        }
        end ^= 1;
    }
    sx = SX;
    while(sx != N){
        sx++;
        if(end) {
            REPR(i,M,0,-1){
                cout << sx << " " << i << endl;
            }
        } else {
            REP(i,1,M+1,1){
                cout << sx << " " << i << endl;
            }
        }
        end ^= 1;        
    }
}

int main(){
    cin >> N >> M >> SX >> SY;
    solve();
    return 0;
}