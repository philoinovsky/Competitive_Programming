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
#define MAXN 100100
#define INF 10001000
int N, Q, D[MAXN], S[MAXN], K[MAXN];
vector<int> res;

void solve(){
    int l,r,cnt,cur;
    res.clear();
    rep(i,Q){
        l = S[i]-1; r = S[i]; cnt = 1; cur = S[i];
        while(cnt < K[i]){
            if(D[l] < D[r]){
                l--; cur = l+1;
            } else {
                r++; cur = r;
            }
            cnt++;
        }
        res.push_back(cur);
    }
    return;
}

int main(){
    // std::ios::sync_with_stdio(false);
    int T, iCase(1);
    cin >> T;
    while(T--){
        scanf("%d%d",&N,&Q);
        rep(i,N-1){ scanf("%d",&D[i+1]); } //D[i] connects room i and i+1
        D[0] = D[N] = INF;
        rep(i,Q){ scanf("%d%d",&S[i],&K[i]); }
        solve();
        printf("Case #%d: ", iCase++);
        for(auto e: res) cout << e << " ";
        cout << endl;
    }
    return 0;
}