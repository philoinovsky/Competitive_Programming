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
int MIN, MAX, MEAN, MED;
//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    //init
    if(MAX < MIN || MED > MAX || MED < MIN || MEAN > MAX || MEAN < MIN){
        cout << "IMPOSSIBLE";
        return;
    }
    if(MIN == MAX && MEAN == MED && MIN == MEAN){
        cout << 1;
        return;
    } else if(MIN + MAX == MEAN * 2 && MIN + MAX == MED * 2){
        cout << 2;
        return;
    } else  if(2 * MEAN - MED < MAX && 2 * MEAN - MED > MIN) {
        int diff = 3 * MEAN - MIN - MAX - MED;
        int odd, even;
        if(diff > 0) {
            int denom = MED + MAX - 2 * MEAN;
            int N = (diff + denom - 1) / denom;
            odd = 2 * N + 3;
        } else if (diff < 0){
            int denom = 2 * MEAN - MIN - MED;
            int N = (-diff + denom - 1) / denom;
            odd = 2 * N + 3;
        } else {
            odd = 3;
        }
        diff = 4 * MEAN - MIN - MAX - 2 * MED;
        if(diff > 0) {
            int denom = MED + MAX - 2 * MEAN;
            int N = (diff + denom - 1) / denom;
            even = 2 * N + 4;            
        } else if (diff < 0) {
            int denom = 2 * MEAN - MIN - MED;
            int N = (-diff + denom - 1) / denom;
            even = 2 * N + 4;
        } else {
            even = 4;
        }
        cout << min(odd,even);
        return;
    } else {
        cout << "IMPOSSIBLE";
        return;
    }
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> MIN >> MAX >> MEAN >> MED;
        printf("Case #%d: ", iCase++);
        solve();
        cout << endl;
    }
    return 0;
}