#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define rep(i,n) for(int i = 0; i < (int)n; ++i)
#define repr(i,n) for(int i = (int)n; i > -1; --i) 
#define REP(i,start,end,step) for(int i = (int)start; i < (int)end; i += (int)step) 
#define REPR(i,start,end,step) for(int i = (int)start; i > (int)end; i += (int)step)
#define repc(i,c) for(auto i = c.begin(); i != c.end(); i++)
#define repcr(i,c) for(auto i = c.rbegin(); i != c.rend(); i++)
#define lowbit(x) ((x) & (-x))
typedef long long ll;
typedef unsigned long long ull;
//global variables
#define MAXN 210
int R, G, B, r[MAXN], g[MAXN], b[MAXN];
unordered_map<ull,ll> m;

//-------------function-starts---------------------
ull hashi(int a, int b, int c){ return 1LL*13331*13331*a + 13331*b + c; }

ll getmax(int rr, int gg, int bb, int MAX){
    int cnt = 0;
    if(rr >= MAX) cnt++;
    if(gg >= MAX) cnt++;
    if(bb >= MAX) cnt++;
    if(cnt >= 2) return 0;
    ll resone = 0, restwo = 0, resthree = 0;
    if(rr < MAX && gg < MAX) {
        ull one = hashi(rr+1,gg+1,bb);
        resone = (m.find(one) != m.end()) ? m[one] : getmax(rr+1,gg+1,bb,MAX);
        resone += r[rr] * g[gg];
    }
    if(bb < MAX && gg < MAX) {
        ull two = hashi(rr,gg+1,bb+1);
        restwo = (m.find(two) != m.end()) ? m[two] : getmax(rr,gg+1,bb+1,MAX);
        restwo += b[bb] * g[gg];
    }
    if(rr < MAX && bb < MAX) {
        ull three = hashi(rr+1,gg,bb+1);
        resthree = (m.find(three) != m.end()) ? m[three] : getmax(rr+1,gg,bb+1,MAX);
        resthree += r[rr] * b[bb];
    }
    ll maxx = max(max(resone,restwo),resthree);
    m[hashi(rr,gg,bb)] = maxx;
    return maxx;
}
//-------------function-ends-----------------------

void solve(){
    m.clear();
    auto comp = [](const int &a, const int &b){ return a > b; };
    sort(r,r+R,comp); sort(g,g+G,comp); sort(b,b+B,comp);
    int MAX = max(max(R,G),B);
    cout << getmax(0,0,0,MAX) << endl;
}

int main(){
    cin >> R >> G >> B;
    memset(r,0,sizeof(int)*MAXN);
    memset(g,0,sizeof(int)*MAXN);
    memset(b,0,sizeof(int)*MAXN);
    rep(i,R) cin >> r[i];
    rep(i,G) cin >> g[i];
    rep(i,B) cin >> b[i];
    solve();
    return 0;
}