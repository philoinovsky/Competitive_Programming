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
#define MAXN 100100
int  N, K, C, D, E1, E2, F, X[MAXN], Y[MAXN], R[MAXN], S[MAXN], A[MAXN], B[MAXN];

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    //init
    R[1] = S[1] = 0;
    A[1] = X[1]; B[1] = Y[1];
    REP(i,2,N+1,1){
        X[i] = (C * X[i-1] + D * Y[i-1] + E1) % F;
        Y[i] = (C * X[i-1] + D * Y[i-1] + E2) % F;
        R[i] = (C * R[i-1] + D * S[i-1] + E1) % 2;
        S[i] = (C * R[i-1] + D * S[i-1] + E2) % 2;
        if(R[i] & 1) A[i] = -X[i];
        else A[i] = X[i];
        if(S[i] & 1) B[i] = -X[i];
        else B[i] = Y[i];
    }
    //do things
    //store results
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> K >> X[1] >> Y[1] >> C >> D >> E1 >> E2 >> F;
        solve();
        printf("Case #%d: \n", iCase++);
    }
    return 0;
}