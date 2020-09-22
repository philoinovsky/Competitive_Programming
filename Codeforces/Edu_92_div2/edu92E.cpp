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
#define all(c) c.begin(), c.end()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
//global variables
const int MAXN = 2e5+10;
int N, L[MAXN], R[MAXN], T[MAXN];

//-----------------segment-tree-min/max/gcd/lcm-start------------------
struct segtree {
	int n;
	vector<int> t, ps;
	segtree(int n) : n(n) {
		t.resize(4 * n, 0);
		ps.resize(4 * n, 0);
	}
	inline void upd(int pos, int val) { return upd(0, 0, n, pos, val); }
	inline void add(int l, int r, int val) { return add(0, 0, n, l, r, val); }
	inline int get(int l, int r) { return get(0, 0, n, l, r); }
private:
    void push(int v, int l, int r) {
		if (l + 1 != r) {
			ps[v * 2 + 1] += ps[v];
			ps[v * 2 + 2] += ps[v];
		}
		t[v] += ps[v];
		ps[v] = 0;
	}
	void upd(int v, int l, int r, int pos, int val) {
		push(v, l, r);
		if (l + 1 == r) { t[v] = val; return; }
		int m = (l + r) >> 1;
		if (pos < m) upd(v * 2 + 1, l, m, pos, val);
		else upd(v * 2 + 2, m, r, pos, val);
		t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
	}
	void add(int v, int l, int r, int L, int R, int val) {
		push(v, l, r);
		if (L >= R) return;
		if (l == L && r == R) { ps[v] += val; push(v, l, r); return; }
		int m = (l + r) >> 1;
		add(v * 2 + 1, l, m, L, min(m, R), val);
		add(v * 2 + 2, m, r, max(m, L), R, val);
		t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
	}
	int get(int v, int l, int r, int L, int R) {
		push(v, l, r);
		if (L >= R) return INT_MIN;
		if (l == L && r == R) return t[v];
		int m = (l + r) >> 1;
		int r1 = get(v * 2 + 1, l, m, L, min(m, R));
		int r2 = get(v * 2 + 2, m, r, max(m, L), R);
		t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
		return max(r1, r2);
	}
};
//-----------------segment-tree-min/max/gcd/lcm-end--------------------

void solve(){
    vector<pii> A[2];
    rep(i,N) A[T[i]-1].push_back(mp(R[i],L[i]));
    rep(i,2) sort(A[i].begin(),A[i].end(),[](pii &a,pii &b){
        return a.fi < b.fi || (a.fi == b.se && a.se > b.se);
    });
	segtree t1(A[0].size() + 1), t2(A[1].size() + 1);
	t1.upd(0, 0);
	t2.upd(0, 0);
	int ans = 0;
	for (int i = 0, j = 0; i + j < N; ) {
		if (i < (int)A[0].size() && (j == (int)A[1].size() || A[0][i].fi <= A[1][j].fi)) {
			int pos = upper_bound(A[1].begin(),A[1].end(), mp(A[0][i].se, INT_MIN)) - A[1].begin() + 1; 
			int cur = t2.get(0, pos) + 1;
			ans = max(ans, cur);
			t1.upd(i + 1, cur);
			t2.add(0, pos, 1);
			++i;
		} else {
			int pos = upper_bound(A[0].begin(),A[0].end(), mp(A[1][j].se, INT_MIN)) - A[0].begin() + 1; 
			int cur = t1.get(0, pos) + 1;
			ans = max(ans, cur);
			t2.upd(j + 1, cur);
			t1.add(0, pos, 1);
			++j;
		}
	}
    cout << ans << endl;
}

int main(){
    //read params to global variables
    cin >> N;
    rep(i,N) cin >> L[i] >> R[i] >> T[i];
    solve();
    return 0;
}