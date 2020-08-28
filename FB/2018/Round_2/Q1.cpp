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
int N, K;
//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    if(N <= 2 || K <= 2){
        cout << 0 << endl;
        cout << 1 << endl;
        cout << 1 << " " << N << " " << 1 << endl;
        return;
    }
    int res = 0, lim = min(N,K);
    REP(i,1,lim,1) res += K - i;
    res -= K;
    cout << res << endl;
    cout << lim << endl;
    cout << 1 << " " << N << " " << K << endl;
    REP(i,1,lim-1,1){
        cout << i << " " << i + 1 << " " << K - i << endl;
    }
    cout << lim-1 << " " << N << " " << K-lim+1 << endl;
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> K;
        printf("Case #%d: ", iCase++);
        solve();
    }
    return 0;
}