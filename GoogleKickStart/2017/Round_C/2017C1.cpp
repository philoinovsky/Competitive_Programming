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
string S;

//-------------function-starts---------------------
//-------------function-ends-----------------------

string solve(){
    //init
    int N = S.size();
    if(N & 1) return "AMBIGUOUS";
    string res;
    res.resize(N);
    res[1] = S[0];
    res[N-2] = S[N-1];
    //do things
    REP(i,2,N,2){
        res[i+1] = (S[i] + 26 - res[i-1]) % 26 + 'A';
    }
    REPR(i,N-3,0,-2){
        res[i-1] = (S[i] + 26 - res[i+1]) % 26 + 'A';
    }
    //store results
    return res;
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> S;
        printf("Case #%d: %s\n", iCase++,solve().c_str());
    }
    return 0;
}