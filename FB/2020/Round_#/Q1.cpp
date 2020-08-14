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
#define MAXN 51
int N;
string S[2];

//-------------function-starts---------------------

//-------------function-ends-----------------------

void solve(){
    //init
    vector<vector<char>> res(N,vector<char>(N,'Y'));
    //do things
    rep(i,N-1) {
        if(S[0][i] != 'Y' || S[1][i+1] != 'Y') res[i+1][i] = 'N';
        if(S[0][i+1] != 'Y' || S[1][i] != 'Y') res[i][i+1] = 'N';
    }
    REP(l,3,N+1,1) rep(i,N-l+1) {
        int j = l + i - 1;
        if(res[i][j-1] != 'Y' || res[j-1][j] != 'Y') res[i][j] = 'N';
        if(res[j-1][i] != 'Y' || res[j][j-1] != 'Y') res[j][i] = 'N';        
    }
    //store results
    for(auto e: res){
        for(auto f: e) cout << f;
        cout << endl;
    }
}

int main(){
    // std::ios::sync_with_stdio(false);
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N; cin.get();
        rep(i,2) cin >> S[i];
        printf("Case #%d: \n", iCase++);
        solve();
    }
    return 0;
}