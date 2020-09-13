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
#define MAXN 6010
int N, K;
int A[MAXN];
int day(0), ans(0), KK;

//solve
void solve(){
    //init
    ans = 0; day = 0;
    //do things
    int id = 0;
    sort(A,A+N);
    while(id < N && day < A[N-1]){
        while(day >= A[id] && id < N) id++;
        if(id >= N) break;
        KK = K;
        while(KK--){
            if(id < N && day < A[id]){
                id++; ans++;
            } else {
                break;
            }
        }
        day++;
    }
    //store results
}

int main(){
    int T;
    int iCase = 1;
    scanf("%d",&T);
    while(T--){
        //read params to global variables
        scanf("%d%d",&N,&K);
        rep(i,N){ scanf("%d",&A[i]); }
        solve();
        printf("Case #%d: %d\n", iCase++, ans);
    }
    return 0;
}