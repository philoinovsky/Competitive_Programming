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
    for(size_t i = 0; i < (uint)range; ++i) std::cout << array[i] << " ";
    cout << endl;}
template<typename T>
void print(const T& t) { //print(vector);
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, " "));
    cout << endl;}
//global variables
#define MAXN 100100
int N, A[MAXN],SUM[MAXN];

//solve
ll solve(){
    SUM[0] = 0;
    ll ans(0);
    int res, len;
    vector<int> perfectsum;
    rep(i,N){ SUM[i+1] = SUM[i] + A[i]; }
    int idx(0), square(0), MAX = *max_element(A,A+N)*N;
    while(square <= MAX){
        perfectsum.push_back(square);
        idx++;
        square = idx * idx;
    }
    const auto p = minmax_element(SUM,SUM+N+1);
    int top = *p.se, base = *p.fi;
    len = top-base+10;
    vector<int> P(len,0);
    rep(i,N){
        P[SUM[i]-base]++;
        for(int e: perfectsum){
            res = SUM[i+1]-e-base;
            if(res >= 0 && res < len)
                ans += P[res];
        }
    }
    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    int T, iCase(1);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        rep(i,N){ scanf("%d",&A[i]); };
        printf("Case #%d: %lld\n", iCase++, solve());
    }
    return 0;
}