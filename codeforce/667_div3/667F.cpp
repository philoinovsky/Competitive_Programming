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
int N, K;
string S, T;

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    if(T[0] == T[1]){
        int cnt = 0;
        rep(i,N) if(S[i] == T[0]) cnt++;
        cnt = min(N,cnt+K);
        cout << cnt * (cnt - 1) / 2 << endl;
    } else {
        int mid0 = 0, mid1 = 0, cnt = 0, cntmid = 0;
        repr(i,N-1){
            if(S[i] == T[0]) {
                mid0++;
                cnt += mid1;
            } else if(S[i] == T[1]) {
                mid1++;
            }
        }
        cntmid = mid0 + mid1;
        int rest = N - cntmid;
        int diff = min(rest,K);
        K -= diff;
        // fill
        int MAX = 0, maxleft = -1;
        rep(i,diff){ // left add i, right add (diff - i)
            int tot = i * (diff - i + mid1) + cnt + mid0 * (diff - i);
            if(tot > MAX){
                MAX = tot;
                maxleft = i;
            }
        }
    }
}

int main(){
    cin >> N >> K; cin.get();
    cin >> S >> T;
    solve();
    return 0;
}