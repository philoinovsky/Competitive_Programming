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
#define MAXN 51
#define SEED 13331
int L;
string A, B;
int ans;

ull gethash(int a[]){
    ull res = 1;
    rep(i,26){ res = res*SEED + a[i]; }
    return res;
}

//solve
void solve(){
    //init
    ans = 0;
    vector<ull> A_hash;
    set<ull> B_hash;
    //do things
    rep(i,L){
        int a[26] = {0}, b[26] = {0};
        REP(j,i,L,1){
            a[A[j]-'A']++;
            b[B[j]-'A']++;
            A_hash.push_back(gethash(a));
            B_hash.insert(gethash(b));
        }
    }
    for(ull e:A_hash){
        if(B_hash.find(e)!=B_hash.end()){
            ans++;
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
        scanf("%d",&L);
        cin >> A >> B;
        solve();
        printf("Case #%d: %d\n", iCase++, ans);
    }
    return 0;
}