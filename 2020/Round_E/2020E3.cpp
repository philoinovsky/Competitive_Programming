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
const int MAXN = 1e5+10;
int N, E[MAXN], R[MAXN];
bool chosen[MAXN];

//-------------function-starts---------------------
//-------------function-ends-----------------------

pair<int,ll> solve(){
    ll SUM = 0, SUM2 = 0;
    int rem = 0, finalrem = 0;
    rep(i,N) SUM += E[i];
    rep(i,N) {
        if(SUM - E[i] < R[i]){
            break;
        } else {
            SUM2 += E[i];
        }
    }
    ll MAX = SUM + SUM2;
    SUM2 = 0;
    priority_queue<pair<int,int>> heap;
    rep(i,N){
        if(SUM - E[i] < R[i]){
            rem++;
            SUM -= E[i];
            while(!heap.empty() && heap.top().first > SUM){
                SUM -= heap.top().second;
                SUM2 -= heap.top().second;
                heap.pop();
                rem++;
            }
            if(SUM2 + SUM > MAX){
                MAX = SUM2 + SUM;
                finalrem = rem;
            }
        } else {
            SUM2 += E[i];
            heap.push(mp((E[i]+R[i]),E[i]));
            if(SUM2 + SUM > MAX){
                MAX = max(MAX, SUM2+SUM);
                finalrem = rem;
            }
        }
    }
    if(!heap.empty()){
        return mp(rem,-1);
    } else {
        return mp(finalrem,MAX);
    }
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N;
        rep(i,N) cin >> E[i] >> R[i];
        pair<int,ll> res = solve();
        printf("Case #%d: ", iCase++);
        if(res.se == -1){
            cout << res.fi << " " << "INDEFINITELY" << endl;
        } else {
            cout << res.fi << " " << res.se << endl;
        }
    }
    return 0;
}