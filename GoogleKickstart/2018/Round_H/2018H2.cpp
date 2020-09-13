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
//global variables
#define MAXN 1000100
int N;
ll MAX, SUM;
char c;
vector<int> num;

//solve
void solve(){
    //init
    MAX = 0;
    SUM = 0;
    //do things
    rep(i,(N+1)/2){
        SUM += num[i];
    }
    MAX = SUM;
    rep(i,N/2){
        SUM -= num[i];
        SUM += num[i+(N+1)/2];
        MAX = max(MAX,SUM);
    }
    //store results
}

int main(){
    int T;
    int iCase = 1;
    scanf("%d",&T);
    while(T--){
        //read params to global variables
        num.clear();
        scanf("%d",&N);
        cin.get(c);
        rep(i,N){ cin.get(c); num.push_back(c-'0');}
        solve();
        printf("Case #%d: %lld\n", iCase++, MAX);
    }
    return 0;
}