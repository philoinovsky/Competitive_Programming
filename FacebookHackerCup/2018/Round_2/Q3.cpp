#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=55;
int n,s,e,rk[N],y[N],ps,pe,_,__;
PII p[N];
int dp[N][N][N][N],pd[N][N][N][N];
void upd(int &a,int b) {
	a+=b; if (a>=mod) a-=mod;
}
void solve() {
	scanf("%d%d%d",&n,&s,&e);
	rep(i,1,n+1) {
		scanf("%d%d",&p[i].fi,&p[i].se);
	}
	sort(p+1,p+n+1);
	rep(i,1,n+1) {
		rk[i]=0;
		rep(j,1,n+1) rk[i]+=(p[j].se<=p[i].se);
		y[rk[i]]=p[i].se;
	}
	y[0]=-1;
	y[n+1]=mod;
	rep(i,0,n+1) {
		if (s>=y[i]&&s<=y[i+1]) {
			ps=i;
		}
		if (e>=y[i]&&e<=y[i+1]) {
			pe=i;
		}
	}
//	printf("%d %d\n",ps,pe);
//	rep(i,1,n+1) printf("%d ",rk[i]); puts("");
	memset(dp,0,sizeof(dp));
	rep(p1,0,ps+1) rep(p2,ps+1,n+2) dp[p1][p2][0][n+1]=1;
	rep(i,1,n+1) {
		rep(p1,0,ps+1) rep(p2,ps+1,n+2) rep(p3,0,pe+1) rep(p4,pe+1,n+2)
			pd[p1][p2][p3][p4]=dp[p1][p2][p3][p4],dp[p1][p2][p3][p4]=0;
		rep(p1,0,ps+1) rep(p2,ps+1,n+2) rep(p3,0,pe+1) rep(p4,pe+1,n+2) if (pd[p1][p2][p3][p4]) {
			int v=pd[p1][p2][p3][p4];
			// constraint from right [p1,p2]
			// constraint from left [p3,p4]
			if (rk[i]==p1) { // L
				rep(p5,0,p1) upd(dp[p5][p2][p3][p4],v);
				continue;
			}
			if (rk[i]==p2) {  // L
				rep(p5,p2+1,n+2) upd(dp[p1][p5][p3][p4],v);
				continue;
			} // L
			if (rk[i]<p1||rk[i]>p2) {
				upd(dp[p1][p2][p3][p4],v);
			}
			// up
			if (rk[i]>max(p1,p3)) upd(dp[p1][p2][p3][p4],v);
			// down
			if (rk[i]<min(p2,p4)) upd(dp[p1][p2][p3][p4],v);
			// R
			if (rk[i]<=pe) upd(dp[p1][p2][max(rk[i],p3)][p4],v);
			else upd(dp[p1][p2][p3][min(rk[i],p4)],v);
		}
	}
	int ans=0;
	rep(p3,0,pe+1) rep(p4,pe+1,n+2) upd(ans,dp[0][n+1][p3][p4]);
	ans=(powmod(2,2*n)-ans+mod)%mod;
	printf("%d\n",ans);
	fprintf(stderr,"%d\n",ans);
}
int main() {
	for (scanf("%d",&_);_;_--) {
		printf("Case #%d: ",++__);
		fprintf(stderr,"Case #%d: ",__);
		solve();
	}
}
