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
#define MAXN 100100
int N, D, M, A[MAXN];

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    sort(A,A+N);
    vector<int> small;
    deque<int> big;
    rep(i,N){
        if(A[i] < M) {
            small.push_back(A[i]);
        } else {
            big.push_back(A[i]);
        }
    }
    int sum = 0;
    if(big.size() < 2){
        rep(i,N) sum += A[i];
        cout << sum << endl;
        return;
    } else {
        int window = 0;
        int bound = min(D,(int)small.size());
        rep(i,bound){
            window += small[i];
        }
        while(!big.empty()){
            sum += big.back();
            big.pop_back();
            if(big.empty()) break;
            if(big.front() > window){

            } else {
                big.pop_front();
            }
        }
    }
}

int main(){
    cin >> N >> D >> M;
    rep(i,N) cin >> A[i];
    solve();
    return 0;
}