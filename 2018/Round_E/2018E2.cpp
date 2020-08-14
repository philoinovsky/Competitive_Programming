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
#define MAXN 110
typedef long long ll;
typedef unsigned long long ull;
//global variables
int N,M,P;
string con[MAXN], fbd[MAXN];
int ans;

void solve(){
    //init
    int zero(0), one(0);
    multimap<int,string> mm;
    vector<pair<int,string>> tmp;
    mm.insert(mp(0,""));
    //do things
    rep(i,P){
        zero = one = 0;
        rep(j,N){
            if(con[j][i] == '0') one++;
            else zero++;
        }
        tmp.clear();
        for(auto e: mm){
            tmp.push_back(mp(e.fi+zero,e.se+"0"));
            tmp.push_back(mp(e.fi+one,e.se+"1"));
        }
        mm.clear();
        for(auto e: tmp) mm.insert(e);
        while((int)mm.size() > M+1) mm.erase(--mm.end());
    }
    std::sort(fbd,fbd+M);
    multimap<int,string>::iterator it = mm.begin();
    while(it!=mm.end()){
        if(find(fbd,fbd+M,it->second)==fbd+M){
            ans = it->first; break;
        } else {
            it++;
        }
    }
    //store results
}

int main(){
    int T;
    int iCase = 1;
    scanf("%d",&T);
    while(T--){
        //read params to global variables
        scanf("%d%d%d",&N,&M,&P);
        rep(i,N){cin >> con[i];}
        rep(i,M){cin >> fbd[i];}
        solve();
        printf("Case #%d: %d\n", iCase++, ans);
    }
    return 0;
}