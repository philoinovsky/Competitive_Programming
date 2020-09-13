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
int L;
ll N, K;

//-------------function-starts---------------------

//-------------function-ends-----------------------

void solve(){
    bool odd = (bool)(N & 1);
    if(K <= N) return K;
    if(L == 1) return 0;
    
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> L >> N >> K;
        solve();
        printf("Case #%d: \n", iCase++);
    }
    return 0;
}