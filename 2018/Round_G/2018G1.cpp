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
#define MAXN 7010
int N, A[MAXN];
ll ans;

//solve
void solve(){
    //init
    ans = 0;
    map<int,int> M;
    vector<int> U;
    int last = -1;
    sort(A,A+N);
    rep(i,N){
        if(last != A[i]){
            last = A[i];
            M[last] = 1;
            if(last > 1){
                U.push_back(last);
            }
        } else {
            M[last]++;
        }
    }
    //do things
    //0
    int cnt = M[0];
    ans += (ll)cnt*(cnt-1)*(cnt-2)/6;
    ans += (ll)cnt*(cnt-1)*(N-cnt)/2;
    //1
    cnt = M[1];
    ans += (ll)cnt*(cnt-1)*(cnt-2)/6;
    if(cnt){
        for(auto e: U){
            cnt = M[e];
            ans += (ll)M[1]*cnt*(cnt-1)/2;
        }
    }
    //>=2
    int f = 0;
    ll tmp = 0;
    while(A[f] < 2 && f < N) f++;
    if(f == N) return;
    REP(i,f,N,1){
        REP(j,i+1,N,1){
            tmp = (ll)A[i]*A[j];
            if(tmp > 200000) break;
            ans += M[tmp];
        }
    }
    //store results
}

int main(){
    int T;
    int iCase = 1;
    scanf("%d",&T);
    while(T--){
        //read params to global variables
        scanf("%d",&N);
        rep(i,N){scanf("%d",&A[i]);}
        solve();
        printf("Case #%d: %lld\n", iCase++, ans);
    }
    return 0;
}