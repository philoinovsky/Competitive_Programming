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
template <typename T, size_t size> void print(const T (&array)[size], int range){ //print(array,N);
    for(size_t i = 0; i < (uint)range; ++i) std::cout << array[i] << " "; 
    cout << endl;
}
template<typename T> void print(const T& t) { //print(vector);
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, " "));
    cout << endl;
}
//global variables
#define MAXN 5010
int N, L[MAXN];

//-------------function-starts---------------------
//-------------function-ends-----------------------

ll solve(){
    //init
    sort(L,L+N);
    map<int,ll> m, counter, mm, mmm;
    rep(i,N) counter[L[i]]++;
    int U[MAXN];
    int last = U[0] = L[0], idx = 1;
    REP(i,1,N,1){
        if(last != L[i]){
            U[idx] = last = L[i];
            idx++;
        }
    }
    int size = idx;
    rep(i,size) REP(j,i+1,size,1) {
        int b = (U[j]-U[i])/2;
        m[b+1] += counter[U[i]] * counter[U[j]];
        mm[U[j]] += counter[U[i]] * counter[U[j]];
        mmm[U[j]] += counter[U[i]];
        if(b < U[i]){
            mm[U[i]] += counter[U[i]] * counter[U[j]];
            mmm[U[i]] += counter[U[j]];
        };
    }
    map<int,ll> suffix, choose2from, choose3from;
    suffix[0] = choose2from[0] = choose3from[0] = 0;
    rep(i,size){
        choose2from[U[i]] = counter[U[i]] * (counter[U[i]] - 1) / 2;
        choose3from[U[i]] = counter[U[i]] * (counter[U[i]] - 1) * (counter[U[i]] - 2) / 6;
    }
    suffix[U[size-1]] = choose2from[U[size-1]];
    repr(i,size-2){
        suffix[U[i]] = suffix[U[i+1]] + choose2from[U[i]];
    }
    suffix[0] = suffix[U[0]];
    //do things
    ll res = 0;
    repc(i,m) {
        if(suffix.find(i->fi) != suffix.end()) {
            res += i->se * suffix[i->fi];
        } else {
            res += i->se * suffix.upper_bound(i->fi)->se;
        }
    }
    repc(i,mm) {
        res -= i->se * choose2from[i->fi];
    }
    repc(i,mmm) {
        res += i->se * choose3from[i->fi];
    }
    //store results
    return res;
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N;
        rep(i,N) cin >> L[i];
        printf("Case #%d: %lld\n", iCase++, solve());
    }
    return 0;
}