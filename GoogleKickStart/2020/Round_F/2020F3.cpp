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
const int MAXN = 40;
int S, RA, PA, RB, PB, C, R[MAXN], P[MAXN];
int D[7] = {0,0,1,4,9,16,25};
map<int,int> row;
set<int> s = {0,1,4,9,16,25,36};
map<pair<ll,pair<int,int>>,int> m;
map<pair<ll,int>,int> mm;
//-------------function-starts---------------------
// convert R and P to pos in mask
inline int getmask(int R, int P){ return (D[R] + P - 1); }

inline pair<int,int> mask2pos(int M){
    int ROW = row[M], COL = M - D[ROW] + 1;
    return mp(ROW,COL);
}

inline pair<ll,pair<int,int>> key(ll mask, int A, int B){ return mp(mask,mp(A,B)); }

int collect(ll mask, int A){
    auto k = mp(mask,A);
    if(mm.find(k) != mm.end()){
        return mm[k];
    } else {
        int MAX = INT_MIN;
        // move A in three directions
        // case 1: left
        if(s.find(A) == s.end() && (mask & (1LL << (A-1))) ){
            // can move left
            MAX = max(MAX,1+collect(mask&~(1LL <<(A-1)),A-1));
        }
        // case 2: right
        if(s.find(A+1) == s.end() && (mask & (1LL << (A+1)))){
            // can move right
            MAX = max(MAX,1+collect(mask&~(1LL<<(A+1)),A+1));
        }
        // case 3: up / down
        pair<int,int> pos = mask2pos(A);
        int ROW = pos.first, COL = pos.second;
        if(COL % 2 == 1){ 
            // down
            if(ROW < S){
                int AA = getmask(ROW+1,COL+1);
                if((mask & (1LL << AA))){
                    // can move down
                    MAX = max(MAX,1+collect(mask&~(1LL<<AA),AA));
                }
            }
        } else {
            // up
            if(ROW != 1){
                int AA = getmask(ROW-1,COL-1);
                if((mask & (1LL << AA))){
                    // can move up
                    MAX = max(MAX,1+collect(mask&~(1LL<<AA),AA));
                }
            }

        }
        mm[k] = max(MAX,0);
        return max(MAX,0);
    }
}

int dp(ll mask, int A, int B){
    auto k = key(mask,A,B);
    if(m.find(k) != m.end()){
        return m[k];
    } else {
        int MAX = INT_MIN;
        // move A in three directions
        // case 1: left
        if(s.find(A) == s.end() && (mask & (1LL << (A-1))) ){
            // can move left
            MAX = max(MAX,1-dp(mask&~(1LL << (A-1)),B,A-1));
        }
        // case 2: right
        if(s.find(A+1) == s.end() && (mask & (1LL << (A+1)))){
            // can move right
            MAX = max(MAX,1-dp(mask&~(1LL << (A+1)),B,A+1));
        }
        // case 3: up / down
        pair<int,int> pos = mask2pos(A);
        int ROW = pos.first, COL = pos.second;
        if(COL % 2 == 1){ 
            // down
            if(ROW < S){
                int AA = getmask(ROW+1,COL+1);
                if((mask & (1LL << AA))){
                    // can move down
                    MAX = max(MAX,1-dp(mask&~(1LL << AA),B,AA));
                }
            }
        } else {
            // up
            if(ROW != 1){
                int AA = getmask(ROW-1,COL-1);
                if((mask & (1LL << AA))){
                    // can move up
                    MAX = max(MAX,1-dp(mask&~(1LL << AA),B,AA));
                }
            }

        }
        if(MAX == INT_MIN){
            // cannot move, let he collect the rest
            int giveup = collect(mask,B);
            m[k] = -giveup;
            return -giveup;
        } else {
            m[k] = MAX;
            return MAX;
        }
    }
}
//-------------function-ends-----------------------

void solve(){
    //init
    m.clear();
    mm.clear();
    ll mask = 0xfffffffff;
    rep(i,C) mask &= ~(1LL << getmask(R[i],P[i]));
    mask &= ~(1LL << getmask(RA,PA));
    mask &= ~(1LL << getmask(RB,PB));
    cout << dp(mask,getmask(RA,PA),getmask(RB,PB)) << endl;
}

int main(){
    int T, iCase(1);
    rep(i,36){
        if(i == 0)          row[i] = 1;
        else if (i < 4)     row[i] = 2;
        else if (i < 9)     row[i] = 3;
        else if (i < 16)    row[i] = 4;
        else if (i < 25)    row[i] = 5;
        else                row[i] = 6;
    }
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> S >> RA >> PA >> RB >> PB >> C;
        rep(i,C) cin >> R[i] >> P[i];
        printf("Case #%d: ", iCase++);
        solve();
    }
    return 0;
}