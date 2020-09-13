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
int N, Q;
string A[2], ans;
int S[2];

//-------------function-starts---------------------
//-------------function-ends-----------------------

int solve(){
    if(N == 1){
        int same = 0;
        rep(i,Q) if(A[0][i] == ans[i]) same++;
        return Q - abs(S[0] - same);
    } else {
        int bothsame(0), bothdiff(0), zerosame(0), onesame(0), same(0), diff(0);
        rep(i,Q){
            if(A[0][i] == A[1][i]){
                same++;
                if(ans[i] == A[0][i]) bothsame++;
                else bothdiff++;
            } else {
                diff++;
                if(ans[i] == A[0][i]) zerosame++;
                else onesame++;
            }
        }
        int corr = (S[0] + S[1] - diff) / 2;
        int zerocorr = S[0] - corr, onecorr = S[1] - corr;
        return bothsame + bothdiff - abs(corr - bothsame) + min(zerosame, zerocorr) + min(onesame, onecorr);
    }
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> Q; cin.get();
        rep(i,N) cin >> A[i];
        cin >> ans;
        rep(i,N) cin >> S[i];
        printf("Case #%d: %d\n", iCase++, solve());
    }
    return 0;
}