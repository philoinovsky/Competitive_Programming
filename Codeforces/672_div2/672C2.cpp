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
const int MAXN = 3e5+10;
int N, Q, A[MAXN], L[MAXN], R[MAXN];
ll sum = 0;

//-------------function-starts---------------------
void erase(int i){
    if(i == 0 || i == N + 1) return;
    if(A[i] > A[i-1] && A[i] > A[i+1]) sum -= A[i];
    if(A[i] < A[i-1] && A[i] < A[i+1]) sum += A[i];
}
void insert(int i){
    if(i == 0 || i == N + 1) return;
    if(A[i] > A[i-1] && A[i] > A[i+1]) sum += A[i];
    if(A[i] < A[i-1] && A[i] < A[i+1]) sum -= A[i];
}
//-------------function-ends-----------------------

void solve(){
    sum = 0;
    REP(i,1,N+1,1){
        if(A[i] > A[i-1] && A[i] > A[i+1]) sum += A[i];
        if (A[i] < A[i-1] && A[i] < A[i+1]) sum -= A[i];
    }
    cout << sum << endl;
    rep(i,Q){
        erase(L[i]-1); erase(L[i]); erase(L[i]+1); 
        if(R[i] > L[i] + 2) erase(R[i]-1);
        if(R[i] > L[i] + 1) erase(R[i]);
        if(R[i] > L[i]) erase(R[i]+1);
        swap(A[L[i]],A[R[i]]);
        insert(L[i]-1); insert(L[i]); insert(L[i]+1); 
        if(R[i] > L[i] + 2) insert(R[i]-1);
        if(R[i] > L[i] + 1) insert(R[i]);
        if(R[i] > L[i]) insert(R[i]+1);
        cout << sum << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> Q;
        A[0] = A[N+1] = 0;
        rep(i,N) cin >> A[i+1];
        rep(i,Q) cin >> L[i] >> R[i];
        solve();
    }
    return 0;
}