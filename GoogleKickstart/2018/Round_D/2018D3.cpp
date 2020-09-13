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
template <typename T, size_t size> void print(const T (&array)[size], int range){ //print(array,N);
    for(size_t i = 0; i < (uint)range; ++i) std::cout << array[i] << " "; 
    cout << endl;
}
template<typename T> void print(const T& t) { //print(vector);
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, " "));
    cout << endl;
}
//global variables
#define MAXR 110
#define MAXW 1010
int R, C, W, RIGHT[MAXR][MAXR][MAXR], DOWN[MAXR][MAXR][MAXR], RCS[MAXR][MAXR], DCS[MAXR][MAXR];
string strs[MAXR], words[2*MAXW];
unordered_map<int,vector<string>> m;

ll quickgcd(ll a,ll b){
    if(a==0) return b;
    if(b==0) return a;
    if(!(a&1)&&!(b&1)) return quickgcd(a>>1,b>>1)<<1;
    else if(!(b&1)) return quickgcd(a,b>>1);
    else if(!(a&1)) return quickgcd(a>>1,b);
    else return quickgcd(abs(a-b),min(a,b));
}

void insertmap(unordered_map<int,vector<string>> &mm, const string &s){
    int n = s.size();
    if(mm.find(n) == mm.end()) mm[n] = vector<string>();
    mm[n].push_back(s);
}

vector<ll> solve(){
    //init
    memset(RIGHT,0,MAXR*MAXR*MAXR); memset(DOWN,0,MAXR*MAXR*MAXR);
    memset(RCS,0,MAXR*MAXR); memset(DCS,0,MAXR*MAXR);
    int cnt(0);
    rep(i,R)rep(j,C){
        REP(k,1,C-j+1,1){
            cnt = 0;
            if(m.find(k) != m.end()) for(string e: m[k]) if(e == strs[i].substr(j,k)) cnt++;
            RIGHT[i][j][k] = RIGHT[i][j][k-1] + cnt * k;
        } //columns
        REP(k,1,R-i+1,1){
            cnt = 0;
            if(m.find(k) != m.end()) for(string e: m[k]){
                bool flag = true;
                rep(l,k) if(strs[i+l][j] != e[l]) { flag = false; break; }
                if(flag) cnt++;
            }
            DOWN[i][j][k] = DOWN[i][j][k-1] + cnt * k;
        } //rows
    } 
    //do things
    cnt = 0;
    ll nm(0), dnm(1), lnm, ldnm; //nominator, denominator, local nominator, local denominator
    repr(i,R) repr(j,C) REP(ki,1,i+1,1) REP(kj,1,j+1,1){
        RCS[ki][kj] = RCS[ki-1][kj] + RCS[ki][kj-1] - RCS[ki-1][kj-1] + RIGHT[i-ki][j-kj][kj];
        DCS[ki][kj] = DCS[ki-1][kj] + DCS[ki][kj-1] - DCS[ki-1][kj-1] + DOWN[i-ki][j-kj][ki];
        lnm = 1LL*RCS[ki][kj] + DCS[ki][kj];
        ldnm = ki + kj;
        if(lnm * dnm > ldnm * nm){
            cnt = 1; nm = lnm; dnm = ldnm;
        } else if (lnm * dnm == ldnm * nm) {
            cnt++;
        }
    }
    //store results
    ll gcd = quickgcd(nm,dnm);
    nm /= gcd; dnm /= gcd;
    return { nm, dnm, cnt };
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        cin >> R >> C >> W; cin.get(); m.clear();
        rep(i,R) getline(cin,strs[i]);
        rep(i,W) {
            getline(cin,words[i]);
            words[W+i] = words[i];
            reverse(words[i].begin(),words[i].end());
            insertmap(m,words[i]); insertmap(m,words[W+i]);
        }
        vector<ll> r = solve();
        printf("Case #%d: %lld/%lld %lld\n", iCase++, r[0], r[1], r[2]);
    }
    return 0;
}