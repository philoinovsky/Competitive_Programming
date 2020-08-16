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
template <typename T, size_t size> void print(const T (&array)[size], int range){ //print(array,N);
    for(size_t i = 0; i < (uint)range; ++i) std::cout << array[i] << " "; 
    cout << endl;
}
template<typename T> void print(const T& t) { //print(vector);
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, " "));
    cout << endl;
}
//global variables
const int MOD = 1000000007;
#define MAXN 1000100
ll N, K, L[MAXN], W[MAXN], H[MAXN], AL, BL, CL, DL, AW, BW, CW, DW, AH, BH, CH, DH;

//-------------function-starts---------------------
struct comp {
	bool operator() (const pair<int,int> &a, const pair<int,int> &b) {
		return a.fi < b.fi && a.se < b.se;
	}
};
//-------------function-ends-----------------------

ll solve(){
    set<pair<int,int>,comp> s;
    s.insert(mp(L[0],L[0]+W[0]));
    ll res = 2 * H[0] + 2 * W[0];
    ll P = res;
    REP(i,1,N,1){
        auto left = s.find(mp(L[i],L[i])), right = s.find(mp(L[i]+W[i],L[i]+W[i]));
        ll interval, heightcount = 0;
        int leftmost, rightmost, leftpoint, rightpoint;
        if(left == s.end()){
            leftmost = leftpoint = L[i];
            heightcount++;
        } else {
            heightcount--;
            leftmost = left->fi;
            leftpoint = left->se;
            s.erase(left);
        }
        if(right == s.end()){
            heightcount++;
            rightmost = rightpoint = L[i] + W[i];
        } else {
            heightcount--;
            rightmost = right->se;
            rightpoint = right->fi;
            if(left != right) {
                s.erase(right);
            } else {
                s.insert(mp(leftmost,rightmost));
                res = (res * P) % MOD;
                continue;
            }
        }
        interval = rightpoint - leftpoint;
        auto iter = s.upper_bound(mp(L[i],L[i]));
        while(iter != s.end() && iter->se < rightpoint){
            interval -= (iter->se - iter->fi);
            heightcount -= 2;
            s.erase(iter++);
        }
        s.insert(mp(leftmost,rightmost));
        P = (P + H[i] * heightcount + interval * 2) % MOD;
        if(P < 0) P += MOD;
        res = (res * P) % MOD;
    }
    return res;
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> K;
        rep(i,K) cin >> L[i];
        cin >> AL >> BL >> CL >> DL;
        rep(i,K) cin >> W[i];
        cin >> AW >> BW >> CW >> DW;
        rep(i,K) cin >> H[i];
        cin >> AH >> BH >> CH >> DH;
        REP(i,K,N,1) {
            L[i] = (AL*L[i-2] + BL*L[i-1] + CL) % DL + 1;
            W[i] = (AW*W[i-2] + BW*W[i-1] + CW) % DW + 1;
            H[i] = (AH*H[i-2] + BH*H[i-1] + CH) % DH + 1;
        }
        printf("Case #%d: %lld\n", iCase++, solve());
    }
    return 0;
}