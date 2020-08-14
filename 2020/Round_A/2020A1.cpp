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
//global variables
#define MAXN 100010
int N, B, A[MAXN], ans;

void solve(){
    ans = 0;
    sort(A,A+N);
    rep(i,N){
        B -= A[i];
        if (B < 0) break; else ans++;
    }
}

int main(){
    int T;
    int iCase = 1;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&B);
        rep(i,N){scanf("%d",&A[i]);}
        solve();
        printf("Case #%d: %d\n", iCase++, ans);
    }
    return 0;
}