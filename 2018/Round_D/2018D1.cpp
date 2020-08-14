#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define rep(i,n) for(uint i = 0; i < n; ++i)
#define repr(i,n) for(int i = n; i > -1; --i) 
#define REP(i,start,end,step) for(uint i = start; i < end; i += step) 
#define REPR(i,start,end,step) for(int i = start; i > end; i += step)
#define lowbit(x) ((x) & (-x))
#define MAXN 500010
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e17;
uint N, O, X1, X2, A, B, C, M;
int L;
ull D;
int S[MAXN], X[MAXN];
ll SUM[MAXN], ans;

void solve(){
    //init
    X[0] = X1; S[0] = X[0] + L; SUM[0] = S[0];
    X[1] = X2; S[1] = X[1] + L; SUM[1] = S[0] + S[1];
    REP(i,2,N,1){
        X[i] = ((ll)A*X[i-1] + (ll)B*X[i-2] + C) % M;
        S[i] = X[i] + L;
        SUM[i] = SUM[i-1] + S[i];
    }
    //do things
    uint r(0), on(0);
    multiset<ll> ms;
    ans = -INF;
    rep(i,N){
        while(r < N && on + (S[r]&1) <= O){
            ms.insert(SUM[r]);
            on += (S[r++]&1);
        }
        if(r <= i){
            r = i + 1;
        } else {
            multiset<ll>::iterator it = ms.lower_bound(D+(SUM[i]-S[i])+1);
            if(it != ms.begin()){
                it--;
                ans = max(ans, (*it) - (SUM[i] - S[i]));
            }
            ms.erase(ms.find(SUM[i]));
            on -= (S[i]&1);
        }
    }
    ms.~multiset();
    return;
}

int main(){
    int T;
    int iCase = 1;
    scanf("%d",&T);
    while(T--){
        scanf("%u%u%llu",&N,&O,&D);
        scanf("%u%u%u%u%u%u%d",&X1,&X2,&A,&B,&C,&M,&L);
        solve();
        if(ans == -INF)
            printf("Case #%d: IMPOSSIBLE\n", iCase++);
        else
            printf("Case #%d: %lld\n", iCase++, ans);
    }
    return 0;
}