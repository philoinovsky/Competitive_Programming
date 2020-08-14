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
int N,K,P;
#define ii i+1
#define jj j+1

int solve(const vector<vector<int>> &stacks){
    vector<vector<int>> sum(N+1,vector<int>(K+1,0));
    vector<int> dp(P+1,0);
    rep(i,N) rep(j,K) sum[ii][jj] = sum[ii][j] + stacks[i][j];
    rep(i,N) REPR(k,P,0,-1) rep(j,K) if(k-(j+1) >= 0) dp[k] = max(dp[k], dp[k-(j+1)] + sum[ii][jj]);
    return dp[P];
}

int main(){
    int T;
    int iCase = 1;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&N,&K,&P);
        vector<vector<int>> stacks(N,vector<int>(K,0));
        rep(i,N) rep(j,K) scanf("%d",&stacks[i][j]);
        printf("Case #%d: %d\n", iCase++, solve(stacks));
    }
    return 0;
}