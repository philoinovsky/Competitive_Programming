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
#define MAXN 52
#define INF 100100
int V,E, F[MAXN];
pair<int,int> nearest[MAXN];

int find(int x) {
    int r = x;
    while(F[r] != r) r = F[r];
    while(F[x] != r) {
        int tmp = F[x];
        F[x] = r;
        x = tmp;
    }
    return r;
}

bool join(int x, int y) {
    int rx = find(x), ry = find(y);
    if(rx != ry) {
        F[rx] = ry;
        return true;
    }
    return false;
}

//solve
ll solve(){
    REP(i,1,V+1,1){
        F[i] = i;
        nearest[i].fi = 0;
        nearest[i].se = INF;
    }
    pair<int,int> zero;
    zero.fi = zero.se = -1;
    rep(i,E) {
        int a, b, l;
        scanf("%d%d%d",&a,&b,&l);
        if(l < nearest[a].se){
            nearest[a].fi = b;
            nearest[a].se = l;
        }
        if(l < nearest[b].se){
            nearest[b].fi = a;
            nearest[b].se = l;
        }
        if (l == 0) {
            zero.fi = a;
            zero.se = b;
        }
    }
    int n = V;
    REP(i,1,V+1,1) if(join(i,nearest[i].fi)) n--;
    if(zero.fi != -1) REP(i,1,V+1,1) 
        if(i != zero.fi && i != zero.se && (nearest[i].fi == zero.fi || nearest[i].fi == zero.se)) 
           n++;
    return 1LL << n;
}

int main(){
    int T;
    int iCase = 1;
    scanf("%d",&T);
    while(T--){
        //read params to global variables
        scanf("%d%d",&V,&E);
        printf("Case #%d: %lld\n", iCase++, solve());
    }
    return 0;
}