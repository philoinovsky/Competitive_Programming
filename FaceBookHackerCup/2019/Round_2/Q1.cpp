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
int N, M, K, A, B, R[2], C[2];

//-------------function-starts---------------------
//-------------function-ends-----------------------

bool solve(){
    if(K == 1) return false;
    int a = (R[0] + C[0]) & 1, b = (R[1] + C[1]) & 1, c = (A + B) & 1;
    return (a == b && a == c);
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> M >> K;
        cin >> A >> B;
        rep(i,K) cin >> R[i] >> C[i];
        printf("Case #%d: ", iCase++);
        char ans = (solve()) ? 'Y' : 'N';
        cout << ans << endl;
    }
    return 0;
}