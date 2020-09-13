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
#define MAXN 10010
int N;
double X[MAXN], Y[MAXN], W[MAXN], Wpre[MAXN];

//-------------function-starts---------------------
//-------------function-ends-----------------------

double solve(){
    //init
    rep(i,N){
        double x = (X[i] + Y[i]) / 2, y = (X[i] - Y[i]) / 2;
        X[i] = x; Y[i] = y;
    }
    sort(X,X+N);
    sort(Y,Y+N);
    Wpre[0] = W[0];
    REP(i,1,N,1){
        Wpre[i] = Wpre[i-1] + W[i];
    }
    //do things
    //store results
    return res;
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N;
        rep(i,N) cin >> X[i] >> Y[i] >> W[i];
        printf("Case #%d: %.10f\n", iCase++, solve());
    }
    return 0;
}