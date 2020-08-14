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
#define MAXN 110
#define MAXM 110
#define obs -100000
int N,M,E,SR,SC,TR,TC;
int V[MAXN][MAXM];

//solve
void solve(){
    //init
    //do things
    //store results
}

int main(){
    int T;
    int iCase = 1;
    scanf("%d",&T);
    while(T--){
        // N, M, E, SR, SC, TR and TC
        //read params to global variables
        scanf("%d%d%d%d%d%d%d",&N,&M,&E,&SR,&SC,&TR,&TC);
        SR--;SC--;TR--;TC--;
        rep(i,N)rep(j,M)scanf("%d",&V[i][j]);
        solve();
        printf("Case #%d: \n", iCase++);
    }
    return 0;
}