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
const int MAXN = 1e5+10;
int N, X, A[MAXN];

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    vector<pair<int,int>> order(N);
    rep(i,N){
        order[i].first = (A[i] - 1) / X;
        order[i].second = i;
    }
    sort(order.begin(),order.end());
    rep(i,N)
        cout << order[i].second + 1 << ' ';
    cout << endl;
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> X;
        rep(i,N) cin >> A[i];
        printf("Case #%d: ", iCase++);
        solve();
    }
    return 0;
}