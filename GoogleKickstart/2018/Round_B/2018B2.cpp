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
#define MAXN 110
const ll MAXP = 1001001001001001000;
const int two15 = 0x10000;
int N,K;
ll P, dp[MAXN][two15];
int A[MAXN], B[MAXN], C[MAXN];
inline int g(int last, int i){ return ((last & 0x00007fff) << 1) | i;}

string solve(){
    //count
    int upb = 0, SUM, digit;
    repr(i,N){
        if(i >= 15) upb = two15;
        else upb = pow(2,i);
        rep(last,upb){
            bool flag = true;
            rep(k,K) if(B[k] == i) {
                SUM = 0; digit = 1;
                rep(jj,B[k]-A[k]+1) if(last & digit<<jj) SUM++;
                if(SUM != C[k]){
                    flag = false;
                    break;
                }                    
            }
            if(flag) if(i == N) dp[i][last] = 1; 
                    else dp[i][last] = min(dp[i+1][g(last,0)] + dp[i+1][g(last,1)], MAXP);
            else dp[i][last] = 0;
        }
    }
    string res;
    int last = 0;
    ll cur = 0;
    rep(i,N){
        if(dp[i+1][g(last,0)] + cur >= P){
            res.push_back('0');
            last = g(last,0);
        } else {
            cur += dp[i+1][g(last,0)];
            res.push_back('1');
            last = g(last,1);
        }
    }
    return res;
}

int main(){
    std::ios::sync_with_stdio(false);
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> K >> P;
        rep(i,K){ cin >> A[i] >> B[i] >> C[i];}
        printf("Case #%d: %s\n", iCase++, solve().c_str());
    }
    return 0;
}