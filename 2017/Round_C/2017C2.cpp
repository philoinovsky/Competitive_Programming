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
#define MAXN 57
int N;
string S[MAXN];
//-------------function-starts---------------------
//-------------function-ends-----------------------

bool solve(){
    rep(i,N){
        bool first = false, second = false;
        int left, right;
        rep(j,N){
            if(S[i][j] == 'X'){
                if(!first) { left = j; first = true; }
                else if(!second) { right = j; second = true; }
                else return false; // more than 2 'X's
            }
        }
        if(!first) return false; // 0 of 'X's
        else if(!second) { // 1 of 'X's
            rep(ii,N) if(S[ii][left] == 'X' && ii != i) return false; // row 1X col > 1X
        } else { // 2 of 'X's
            int leftdown = -1, rightdown = -1;
            rep(ii,N) if(S[ii][left] == 'X' && ii != i){
                if(leftdown == -1) leftdown = ii;
                else return false; // too many 'X' in the col                
            }
            rep(ii,N) if(S[ii][right] == 'X' && ii != i){
                if(rightdown == -1) rightdown = ii;
                else return false; // too many 'X' in the col                
            }
            if(leftdown != rightdown || leftdown == -1) 
                return false;          
        }
    }
    return true;
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N; cin.get();
        rep(i,N) cin >> S[i];
        string res = (solve()) ? "POSSIBLE" : "IMPOSSIBLE";
        printf("Case #%d: %s\n", iCase++, res.c_str());
    }
    return 0;
}