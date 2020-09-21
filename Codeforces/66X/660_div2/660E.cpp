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
const int MAXN = 2010;
int N;

//-------------function-starts---------------------
struct comp {
	bool operator() (const pair<double,double> &a, const pair<double,double> &b) {
		return a.fi < b.fi && a.se < b.se;
	}
};
//-------------function-ends-----------------------

void solve(){
    set<pair<double,double>,comp> s;
}

int main(){
    cin >> N;
    rep(i,N){

    }
    solve();
    return 0;
}