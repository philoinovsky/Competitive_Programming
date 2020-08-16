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
class node {
public:
    int height, left, right;
    node(){}
    node(int h):height(h),left(h),right(h){}
    node(int h, int l, int r):height(h),left(l),right(r){}
};
struct comp {
	bool operator() (const pair<int,int> &a, const pair<int,int> &b) {
		return a.fi < b.fi && a.se < b.se;
	}
};
//-------------function-ends-----------------------

ll solve(){
    map<pair<int,int>,node,comp> m; //height, remaining sides
    m[mp(L[0],L[0]+W[0])] = node(H[0]);
    ll res = 2 * H[0] + 2 * W[0];
    ll P = res;
    REP(i,1,N,1){
        int leftpoint = L[i], rightpoint = L[i] + W[i];
        auto left = m.find(mp(L[i],L[i])), right = m.find(mp(L[i]+W[i],L[i]+W[i]));
        ll interval = W[i], totheight = 2 * H[i];
        int leftmost, rightmost;
        if(left == right && left != m.end()){
            leftmost = left->fi.fi;
            rightmost = right->fi.se;
            node tmpnode = left->se, candidate = node(H[i]);
            m.erase(left);
            if(leftmost != leftpoint){
                m[mp(leftmost,leftpoint-1)] = node(tmpnode.height,tmpnode.left,0);
                candidate.left -= tmpnode.height;
            } else {
                candidate.left -= tmpnode.height - tmpnode.left;
            }
            if(rightmost != rightpoint){
                m[mp(rightpoint+1,rightmost)] = node(tmpnode.height,0,tmpnode.right);
                candidate.right -= tmpnode.height;
            } else {
                candidate.right -= tmpnode.height - tmpnode.right;
            }
            m[mp(leftpoint,rightpoint)] = candidate;
            P = (P + 2 * (H[i] - tmpnode.height)) % MOD;
            res = (res * P) % MOD;
            continue;
        }
        node candidate = node(H[i]);
        if(left != m.end()) {
            leftmost = left->fi.fi;
            totheight -= left->se.height;
            interval -= (left->fi.se - leftpoint);
            node tmpnode = left->se;
            totheight -= tmpnode.right;
            m.erase(left);
            if(leftmost != leftpoint){
                m[mp(leftmost,leftpoint-1)] = node(tmpnode.height,tmpnode.left,0);
                candidate.left -= tmpnode.height;
            } else {
                candidate.left -= tmpnode.height - tmpnode.left;
            }
        }
        auto iter = m.upper_bound(mp(L[i],L[i]));
        while(iter != m.end() && iter->fi.se < rightpoint){
            interval -= (iter->fi.se - iter->fi.fi);
            if(iter->se.left < iter->se.height) interval--;
            totheight -= iter->se.left + iter->se.right;
            m.erase(iter++);
        }
        if(right != m.end()){
            rightmost = right->fi.se;
            totheight -= right->se.height;
            interval -= (rightpoint - right->fi.fi);
            if(right->se.left < right->se.height) interval--;
            node tmpnode = right->se;
            totheight -= tmpnode.left;
            m.erase(right);
            if(rightpoint != rightmost){
                m[mp(rightpoint+1,rightmost)] = node(tmpnode.height,0,tmpnode.right);
                candidate.right -= tmpnode.height;
            } else {
                candidate.right -= tmpnode.height - tmpnode.right;
            }
        }
        m[mp(leftpoint,rightpoint)] = candidate;
        P = (P + totheight + interval * 2) % MOD;
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