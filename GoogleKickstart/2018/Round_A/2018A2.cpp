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
#define MAXN 50100
typedef long long ll;
int N,K;
ll post_sum[MAXN];
int a[MAXN];
double dp[MAXN];

void solve(){
    //init
    sort(a,a+N);
    post_sum[N-1] = a[N-1];
    REPR(i,N-2,-1,-1){
        post_sum[i] = post_sum[i+1] + a[i];
    }
    dp[0] = (double)post_sum[0]/(double)N;
    //do things
    REP(i,1,K+1,1){
        int idx = upper_bound(a,a+N,dp[i-1]) - a;
        if(idx >= N){
            dp[i] = dp[i-1];
        } else {
            dp[i] = ((double)post_sum[idx]+dp[i-1]*idx)/(double)N;
        }
    }
}

int main(){
    int T;
    int iCase = 0;
    scanf("%d",&T);
    while(T--){
        iCase++;
        scanf("%d%d",&N,&K);
        rep(i,N) { scanf("%d",&a[i]); }
        solve();
        printf("Case #%d: %.6f\n", iCase,dp[K]);
    }
    return 0;
}