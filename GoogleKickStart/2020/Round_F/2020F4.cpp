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
const int MAXN = 55;
ll N, M, K, A[MAXN];

//-------------function-starts---------------------
void gen(deque<vector<int>> &res){
    while(res.size() < N){
        int NN = res.size();
        rep(j,NN){
            rep(i,M){
                vector<int> tmp = res.front();
                tmp.push_back(i);
                res.push_back(tmp);
            }
            res.pop_front();
        }
    }
}
//-------------function-ends-----------------------

void solve(){
    double pp = (double)1/(double)M;
    double p = 1;
    // one slice probability
    rep(i,N) p *= pp;
    deque<vector<int>> res;
    rep(i,M) res.push_back({i});
    gen(res);
    int NN = res.size();
    ll tot = 0;
    rep(i,NN){
        sort(res[i].begin(),res[i].end());
        int last = -1;
        int start = -1;
        int cnt[6] = {0};
        rep(j,N){
            if(res[i][j] != last){
                last = res[i][j];
                cnt[++start] = 1;
            } else {
                cnt[start]++;
            }
        }
        rep(j,K) if(cnt[j] == A[j]) tot++;
    }
    cout << 1 / p * tot << endl;
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> M >> K;
        rep(i,K) cin >> A[i];
        printf("Case #%d: ", iCase++);
        solve();
    }
    return 0;
}