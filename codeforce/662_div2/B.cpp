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
int N, Q, A[MAXN], X[MAXN];
char S[MAXN];

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    //init
    map<int,int> counter;
    rep(i,N){
        counter[A[i]]++;
    }
    set<int> eight, six, four, two;
    repc(i,counter){
        int n = i->se;
        if(n >= 8) eight.insert(i->fi);
        if(n >= 6) six.insert(i->fi);
        if(n >= 4) four.insert(i->fi);
        if(n >= 2) two.insert(i->fi);
    }
    rep(i,Q) {
        int n = X[i];
        if(S[i] == '+') {
            counter[n]++;
            switch (counter[n]) {
            case 8: eight.insert(n); break;
            case 6: six.insert(n); break;
            case 4: four.insert(n); break;
            case 2: two.insert(n); break;
            default: break;
            }
        } else {
            counter[n]--;
            switch (counter[n]) {
            case 7: eight.erase(n); break;
            case 5: six.erase(n); break;
            case 3: four.erase(n); break;
            case 1: two.erase(n); break;
            default: break;            
            }
        }
        if( eight.size() >= 1 ||
            (six.size() >= 1 && two.size() >= 2) ||
            four.size() >= 2 || 
            (four.size() >= 1 && two.size() >= 3)) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << endl;
    }
    return;
}

int main(){
    cin >> N;
    rep(i,N) cin >> A[i];
    cin >> Q;
    rep(i,Q) cin >> S[i] >> X[i];
    solve();
    return 0;
}