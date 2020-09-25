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
const int MAXN = 3e5 + 10, mod = 998244353;
int N, K, L[MAXN], R[MAXN];

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    sort(L,L+N);
    sort(R,R+N);
    int cnt = 0;
    ll sum = 0;
    for(int i = 0, j = 0; i < N || j < N; ){
        if(j == N || (i != N && L[i] <= R[i])){
            // choose L
            cnt++;
            if(cnt >= K){
                
            }
            i++;
        } else {
            // choose R
            cnt--;
            j++;
        }
    }
}

int main(){
    cin >> N >> K;
    rep(i,N) cin >> L[i] >> R[i];
    solve();
    return 0;
}