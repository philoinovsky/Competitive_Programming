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
template <typename T, size_t size> void print(const T (&array)[size], int range){ //print(array,N);
    for(size_t i = 0; i < (uint)range; ++i) std::cout << array[i] << " "; 
    cout << endl;
}
template<typename T> void print(const T& t) { //print(vector);
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, ", "));
    cout << endl;
}
//global variables
#define MAXN 200100
int N, A[MAXN];

int solve(){
    if(N == 1) return 1;
    int MAX(A[0]), ans(0);
    if(A[0] > A[1]) ans++;
    REP(i,1,N-1,1){
        if(A[i] > MAX && A[i] > A[i+1]){
            ans++;
            MAX = A[i];
        }
    }
    if(A[N-1] > MAX) ans++;
    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    int T, iCase(1);
    scanf("%d",&T);
    while(T--){
        //read params to global variables
        scanf("%d",&N);
        rep(i,N){ scanf("%d",&A[i]); }
        printf("Case #%d: %d\n", iCase++,solve());
    }
    return 0;
}