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
const int MAXN = 8010;
int N;
double P, dp[MAXN], tmp[MAXN];

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    dp[0] = dp[1] = 1;
    REP(NN,2,N,1){
        rep(i,NN){
            tmp[i] = dp[i];
            dp[i] = (NN + 1) * NN / 2;
        }
        dp[NN] = (NN + 1) * NN / 2;
        rep(i,NN+1){
            // total = NN + 1
            // left count = i, right count = NN - i
            // left and left
            if(i > 0)
                dp[i] += i * (i - 1) * tmp[i-1] / 2;
            // left and right
            if(i > 0 && i < NN)
                dp[i] += i * (NN - i) * (P * tmp[i-1] + (1 - P) * tmp[i]);
            // right and right
            if(i < NN)
                dp[i] += (NN - i) * (NN - i - 1) * tmp[i] / 2;
            // self and left
            if(i > 0)
                dp[i] += i * P * tmp[i-1];
            // self and right
            if(i < NN)
                dp[i] += (NN - i) * (1 - P) * tmp[i];
            dp[i] /= (NN + 1) * NN / 2;;
        }
    }
    rep(i,N){
        printf("%.10f\n", dp[i]);
    }
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> P;
        printf("Case #%d: \n", iCase++);
        solve();
    }
    return 0;
}