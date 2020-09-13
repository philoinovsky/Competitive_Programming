// passed small cases
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
#define MAXN 101000
int N,K;
int p1,p2,A1,B1,C1,M1;
int h1,h2,A2,B2,C2,M2;
int x1,x2,A3,B3,C3,M3;
int Y1,y2,A4,B4,C4,M4;
int p[MAXN], h[MAXN], x[MAXN], y[MAXN];
int ans;
vector<pair<int,int>> vec1,vec2;

//solve
void solve(){
    //init
    p[1] = p1; p[2] = p2;
    h[1] = h1; h[2] = h2;
    x[1] = x1; x[2] = x2;
    y[1] = Y1; y[2] = y2;
    vec1.resize(N); vec2.resize(K);
    vec1[0] = mp(p[1]+h[1],h[1]-p[1]);
    vec1[1] = mp(p[2]+h[2],h[2]-p[2]);
    vec2[0] = mp(x[1]+y[1],y[1]-x[1]);
    vec2[1] = mp(x[2]+y[2],y[2]-x[2]); 
    REP(i,3,N+1,1){
        p[i] = ((ll)A1*p[i-1] + (ll)B1*p[i-2] + C1) % M1 + 1;
        h[i] = ((ll)A2*h[i-1] + (ll)B2*h[i-2] + C2) % M2 + 1;
        vec1[i-1] = mp(p[i]+h[i],h[i]-p[i]);
    }
    REP(i,3,K+1,1){
        x[i] = ((ll)A3*x[i-1] + (ll)B3*x[i-2] + C3) % M3 + 1;
        y[i] = ((ll)A4*y[i-1] + (ll)B4*y[i-2] + C4) % M4 + 1;
        vec2[i-1] = mp(x[i]+y[i],y[i]-x[i]);      
    }   
    ans = 0;
    //do things
    sort(vec1.begin(),vec1.end()); reverse(vec1.begin(),vec1.end());
    sort(vec2.begin(),vec2.end()); reverse(vec2.begin(),vec2.end());
    int id = 0;
    int maxY = -0x3f3f3f3f;
    rep(i,K){
        while(id < N && vec1[id].fi >= vec2[i].fi){
            maxY = max(maxY,vec1[id].se);
            id++;
        }
        if(maxY >= vec2[i].se){
            ans++;
        }
    }
    //store results
}

int main(){
    int T;
    int iCase = 1;
    scanf("%d",&T);
    while(T--){
        scanf("%u%u",&N,&K);
        scanf("%u%u%u%u%u%u",&p1,&p2,&A1,&B1,&C1,&M1);
        scanf("%u%u%u%u%u%u",&h1,&h2,&A2,&B2,&C2,&M2);
        scanf("%u%u%u%u%u%u",&x1,&x2,&A3,&B3,&C3,&M3);
        scanf("%u%u%u%u%u%u",&Y1,&y2,&A4,&B4,&C4,&M4);
        solve();
        printf("Case #%d: %d\n", iCase++, ans);
    }
    return 0;
}