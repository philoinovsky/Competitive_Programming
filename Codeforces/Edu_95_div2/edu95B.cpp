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
//global variables
const int MAXN = 110;
int N, A[MAXN], L[MAXN];

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    deque<int> lock, unlock;
    rep(i,N){
        if(L[i]){
            lock.push_back(A[i]);
        } else {
            unlock.push_back(A[i]);
        }
    }
    sort(unlock.begin(), unlock.end());
    rep(i,N){
        if(L[i]){
            cout << lock.front() << ' ';
            lock.pop_front();
        } else {
            cout << unlock.back() << ' ';
            unlock.pop_back();
        }
    }
    cout << endl;
    //init
    //do things
    //store results
}

int main(){
    int T;
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N;
        rep(i,N) cin >> A[i];
        rep(i,N) cin >> L[i];
        solve();
    }
    return 0;
}