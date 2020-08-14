#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define rep(i,n) for(int i = 0; i < n; ++i)
#define repr(i,n) for(int i = n; i > -1; --i) 
#define REP(i,start,end,step) for(int i = start; i < end; i += step) 
#define REPR(i,start,end,step) for(int i = start; i > end; i += step)
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
#define MAXN 100100
#define INF 100100100100100100
int N, P, S[MAXN];
ll presum[MAXN] = {0};
//-------------function-starts---------------------

//-------------function-ends-----------------------

ll solve(){
    //init
    sort(S+1,S+N+1);
    REP(i,1,N+1,1){
        presum[i] = presum[i-1] + S[i];
    }
    //do things
    ll MIN = INF;
    REP(i,P,N+1,1){
        MIN = min(MIN, 1LL * P * S[i] - (presum[i] - presum[i-P]));
    }
    //store results
    return MIN;

}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> P;
        rep(i,N) cin >> S[i+1]; //index starts from one
        printf("Case #%d: %lld\n", iCase++,solve());
    }
    return 0;
}