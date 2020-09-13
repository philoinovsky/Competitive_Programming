#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define rep(i,n) for(int i = 0; i < n; ++i)
#define repr(i,n) for(int i = n; i > -1; --i) 
#define REP(i,start,end,step) for(int i = start; i < end; i += step) 
#define REPR(i,start,end,step) for(int i = start; i > end; i += step)
#define lowbit(x) ((x) & (-x))
typedef long long ll;
typedef unsigned long long ull;
template <typename T, size_t size>
void print(const T (&array)[size], int range){ //print(array,N);
    for(size_t i = 0; i < range; ++i)
        std::cout << array[i] << " ";
}
template<typename T>
void print(const T& t) { //print(vector);
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, ", "));
}
//global variables
#define MAXN 110
int N, H[MAXN], ans;

void solve(){
    ans = 0;
    REP(i,1,N-1,1){ if (H[i] > H[i-1] && H[i] > H[i+1]) ans++; }
}

int main(){
    int T, iCase(1);
    scanf("%d",&T);
    while(T--){
        //read params to global variables
        cin >> N;
        rep(i,N){ cin >> H[i]; }
        solve();
        printf("Case #%d: %d\n", iCase++, ans);
    }
    return 0;
}