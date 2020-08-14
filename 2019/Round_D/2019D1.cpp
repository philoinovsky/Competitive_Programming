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
#define MAXN 100100
int N, Q, A[MAXN], P[MAXN], V[MAXN];

//-------------function-starts---------------------
bool iseven(int SUM){
    int cnt = 0, bit = 1;
    while(SUM >= bit){
        if(SUM & bit) cnt++;
        bit <<= 1;
    }
    return !(cnt % 2);
}
//-------------function-ends-----------------------

void solve(){
    //init
    int SUM = 0;
    set<int> s;
    rep(i,N) {
        SUM ^= A[i];
        if(!iseven(A[i])) s.insert(i);
    }
    //do things
    vector<int> res;
    rep(i,Q){
        SUM ^= A[P[i]];
        A[P[i]] = V[i];
        SUM ^= V[i];
        if(s.find(P[i]) != s.end() && iseven(V[i])) {
            s.erase(P[i]);
        } else if (!iseven(V[i])){
            s.insert(P[i]);
        }
        if(iseven(SUM)) {
            res.push_back(N);
        } else {
            if(s.empty()) res.push_back(0);
            else res.push_back(max(N-1-*s.begin(),*s.rbegin()));
        }
    }
    print(res);
    //store results
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> Q;
        rep(i,N) cin >> A[i];
        rep(i,Q) cin >> P[i] >> V[i];
        printf("Case #%d: ", iCase++);
        solve();
    }
    return 0;
}