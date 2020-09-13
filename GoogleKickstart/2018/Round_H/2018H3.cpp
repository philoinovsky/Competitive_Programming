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
#define MOD 1000000007
#define MAXN 100010
int N, M;
int twopow[MAXN] = {1};
int permutation[2*MAXN] = {1};
int combination[MAXN] = {1};
ll ans, tmp;

int exgcd(int a, int b, int &x, int &y){
    if(b==0){
        x = 1; y = 0;
        return a;
    } else {
        int _gcd = exgcd(b, a%b, x, y);
        int tmp = x - (a/b)*y;
        x = y; y = tmp;
        return _gcd;
    }
}

//a*x=1(mod b)
int mod_reverse(int a,int b){
    int d,x,y;
    d = exgcd(a,b,x,y);
    if(d == 1){
        return (x % b + b) % b;
    } else {
        return -1;
    }
}

void solve(){
    REP(i,1,M+1,1){combination[i] = tmp = (((ll)combination[i-1] * (M - i + 1) % MOD) * mod_reverse(i,MOD)) % MOD;}
    ans = 0;
    rep(i,M+1){        
        if(i&1) tmp = -1; else tmp = 1;
        tmp =  (((tmp * twopow[i] * permutation[2*N-i]) % MOD) * combination[i]) % MOD;
        ans = (ans + tmp) % MOD;
    }
    if(ans < 0) ans += MOD;
}

int main(){
    int T;
    int iCase = 1;
    scanf("%d",&T);
    REP(i,1,MAXN,1){ twopow[i] = ((ll)2*twopow[i-1]) % MOD; }
    REP(i,1,2*MAXN,1){ permutation[i] = ((ll)i*permutation[i-1]) % MOD; }
    while(T--){
        scanf("%d%d",&N,&M);
        solve();
        printf("Case #%d: %lld\n", iCase++, ans);
    }
    return 0;
}