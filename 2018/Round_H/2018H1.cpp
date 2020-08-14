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
#define MAXN 101
int N,P;
string fob[MAXN];
ll ans;
vector<string> U;

void solve(){
    ans = 0;
    auto comp = [](const string &s1, const string &s2){ 
        return s1.size() < s2.size();
    };
    sort(fob,fob+P,comp);
    U.clear();
    bool flag;
    rep(i,P){
        flag = true;
        for(auto e:U){
            if(fob[i].rfind(e,0)==0){
                flag = false;
                break;
            }
        }
        if(flag){
            U.push_back(fob[i]);
        }
    }
    ans = pow(2,N);
    for(auto e:U){
        ans -= pow(2,N-e.size());
    }
}

int main(){
    int T;
    int iCase = 1;
    scanf("%d",&T);
    while(T--){
        //read params to global variables
        scanf("%d%d",&N,&P);
        rep(i,P){ cin >> fob[i]; }
        solve();
        printf("Case #%d: %lld\n", iCase++, ans);
    }
    return 0;
}