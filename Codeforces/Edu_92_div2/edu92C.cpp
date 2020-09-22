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
string S;

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    int cnt[10] = {0}, N = S.size();
    rep(i,N) cnt[S[i]-'0']++;
    int odd = *max_element(cnt,cnt+10);
    int even = 0;
    rep(i,10) REP(j,i+1,10,1){
        char o = '0' + i, s = '0' + j;
        int start, cnt = 0;
        rep(i,N) if(S[i] == o || S[i] == s) {
            start = i;
            cnt = 1;
            break;
        }
        if(cnt == 0) continue;
        if(S[start] == o) swap(o,s);
        REP(i,start+1,N,1){
            if(S[i] == o) {
                swap(o,s);
                cnt++;
            }
        }
        even = max(even,cnt & ~1);
    }
    cout << N - max(odd,even) << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        //read params to global variables
        cin.get();
        cin >> S;
        solve();
    }
    return 0;
}