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
const int MAXN = 1e5+10;
int N, Q, P[MAXN], T[MAXN], X[MAXN];

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    set<int> s;
    multiset<int> diff;
    rep(i,N)
        s.insert(P[i]);
    int range = (s.size() >= 2) ? (*prev(s.end()) - *s.begin()) : 0;
    for(auto i = s.begin(); i != prev(s.end()); i++)
        diff.insert(*next(i) - *i);
    (s.size() <= 2) 
        ?   cout << 0 << endl
        :   cout << range - *prev(diff.end()) << endl;
    rep(i,Q){
        if(T[i] == 0){
            auto iter = s.find(X[i]);
            if(s.size() == 1){
                // pass
            } else if(iter == s.begin() || iter == prev(s.end())){
                int dif = (iter == s.begin()) ? (*next(iter) - *iter) : (*iter - *prev(iter));
                diff.erase(diff.find(dif));
            } else {
                int dif1 = *next(iter) - *iter;
                int dif2 = *iter - *prev(iter);
                diff.erase(diff.find(dif1));
                diff.erase(diff.find(dif2));
                diff.insert(dif1+dif2);
            }
            s.erase(iter);
        } else {
            s.insert(X[i]);
            auto iter = s.find(X[i]);
            if(s.empty()){
                // pass
            } else if (iter == s.begin() || iter == prev(s.end())) {
                int dif = (iter == s.begin()) ? (*next(iter) - *iter) : (*iter - *prev(iter));
                diff.insert(dif);
            } else {
                int dif1 = *next(iter) - *iter;
                int dif2 = *iter - *prev(iter);
                diff.erase(diff.find(dif1+dif2));
                diff.insert(dif1);
                diff.insert(dif2);
            }
        }
        range = (s.size() >= 2) ? (*prev(s.end()) - *s.begin()) : 0;
        (s.size() <= 2) 
            ?   cout << 0 << endl
            :   cout << range - *prev(diff.end()) << endl;
    }
}

int main(){
    //read params to global variables
    cin >> N >> Q;
    rep(i,N) cin >> P[i];
    rep(i,Q) cin >> T[i] >> X[i];
    solve();
    return 0;
}