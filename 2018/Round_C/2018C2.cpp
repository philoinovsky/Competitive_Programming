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
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, " "));
    cout << endl;
}
//global variables
#define MAXN 17
int N, L[MAXN][MAXN], B[MAXN][MAXN], ans;

void dfs(int from, int cm, int SUM, int MAX) {
    if(SUM > 2 * MAX) ans++;
    while (from < N){
        if(!(cm & (1 << from))) REP(i,1,B[from][0]+1,1){
            int to = B[from][i];
            if(!(cm & (1 << to))){
                dfs(from + 1, cm | (1<<from) | (1<<to), SUM + L[from][to], max(MAX,L[from][to]));
            }
        }
        from++;
    }
}

void solve(){
    rep(i,N){
        B[i][0] = 0;
        REP(j,i+1,N,1) if(L[i][j] > 0) B[i][++B[i][0]] = j;
    }
    ans = 0;
    dfs(0,0,0,0);
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        cin >> N;
        rep(i,N) rep(j,N) cin >> L[i][j];
        solve();
        printf("Case #%d: %d\n", iCase++, ans);
    }
    return 0;
}