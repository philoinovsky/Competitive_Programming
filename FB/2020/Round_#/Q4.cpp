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
#define MAXN 1001000
int N, M, C[MAXN];
ll dis[MAXN];
//-------------function-starts---------------------

//-------------function-ends-----------------------

void solve(){
    //init
    REP(i,1,1+M,1){
        dis[i] = 
    }
    //do things
    //store results
}

int main(){
    // std::ios::sync_with_stdio(false);
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> M;
        rep(i,N) cin >> C[i];
        solve();
        printf("Case #%d: \n", iCase++);
    }
    return 0;
}