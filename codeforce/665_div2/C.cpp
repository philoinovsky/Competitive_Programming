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
const int MAXN = 1e5+10;
// const int MAXN = 10;
int N, A[MAXN], B[MAXN];
//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    int MIN = *min_element(A,A+N);
    sort(B,B+N);
    rep(i,N){
        if(A[i] != B[i] && __gcd(A[i],MIN) != MIN){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N;
        rep(i,N) {
            cin >> A[i];
            B[i] = A[i];
        }
        solve();
    }
    return 0;
}