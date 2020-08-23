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
int N, A, B, C;
//-------------function-starts---------------------
//-------------function-ends-----------------------

deque<int> solve(){
    if(A < C || B < C || (N < A + B - C)){
        return deque<int>();
    }
    deque<int> res;
    rep(i,C) res.push_back(N);
    int leftN = A - C, rightN = B - C, invis = N - (A + B - C);
    if(invis > 0){
        if(leftN > 0){
            rep(i,invis) res.push_front(1);
        } else if (rightN > 0){
            rep(i,invis) res.push_back(1);
        } else {
            if(C == 1){
                return deque<int>();
            } else {
                deque<int> spec;
                rep(i,N-C) spec.push_back(1);
                spec.push_back(N);
                spec.push_front(N);
                rep(i,C-2) spec.push_back(N);
                return spec;
            }
        }
    }
    int left = N - 1, right = N - 1;
    rep(i,leftN){
        res.push_front(left--);
    }
    rep(i,rightN){
        res.push_back(right--);
    }
    return res;
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> A >> B >> C;
        deque<int> res = solve();
        printf("Case #%d: ", iCase++);
        if(res.empty()){
            cout << "IMPOSSIBLE" << endl;
        } else {
            for(auto e: res) cout << e << " ";
            cout << endl;
        }
    }
    return 0;
}