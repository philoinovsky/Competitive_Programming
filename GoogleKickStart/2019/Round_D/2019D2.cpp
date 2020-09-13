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
#define MAXG 100100
int N, G, M, H[MAXG], clk[MAXG], anclk[MAXG], res[MAXG];
pair<pair<int,char>,int> guests[MAXG];
char D[MAXG];
map<ll,vector<int>> m;

//-------------function-starts---------------------
inline ll hashi(int a, int b){ return 1LL * 1000000007 * a + b; }
//-------------function-ends-----------------------

void solve(){
    //init
    int MM = M % N;
    if(M >= N) MM += N;
    rep(i,G){
        if(D[i] == 'A')
            H[i] = (H[i] - 1 - MM + 2*N) % N;
        else
            H[i] = (H[i] - 1 + MM) % N;
        guests[i] = mp(mp(H[i],D[i]),i); 
    }
    auto comp = [](const pair<pair<int,char>,int> &a, const pair<pair<int,char>,int> &b){
        return (a.fi.se > b.fi.se) ? true : ((a.fi.se < b.fi.se) ? false : (a.fi.fi < b.fi.fi));
    };
    sort(guests,guests+G,comp);
    // rep(i,G) cout << guests[i].fi.fi << " " << guests[i].fi.se << " " << guests[i].se << endl;
    memset(clk,0x7F,sizeof(int)*(N+1));
    memset(anclk,0x7F,sizeof(int)*(N+1));
    memset(res,0,sizeof(int)*(G+1));
    //do things
    m.clear();
    rep(i,G){
        if(guests[i].fi.se == 'C'){
            clk[guests[i].fi.fi] = 0;
        } else {
            anclk[guests[i].fi.fi] = 0;
        }
    }
    int idx = 0;
    while(guests[idx].fi.se == 'C'){
        rep(i,MM+1){
            int index = (guests[idx].fi.fi - i + 2*N) % N;
            if(clk[index] < i){
                break;
            } else {
                clk[index] = i;
                m[hashi(index,i)].push_back(guests[idx].se);
                //add to res
            }
        }
        idx++;
    }
    while(idx < G){
        rep(i,MM+1){
            int index = (guests[idx].fi.fi + i) % N;
            if(anclk[index] < i){
                break;
            } else {
                anclk[index] = i;
                m[hashi(index,i)].push_back(guests[idx].se);
                //add to res;
            }
        }
        idx++;
    }
    // print(clk,N);
    // print(anclk,N);
    //store results
    rep(i,N) {
        int MIN = min(clk[i],anclk[i]);
        if(MIN < MM + 1) for(auto e: m[hashi(i,MIN)]) res[e]++;
    }
    rep(i,G) cout << res[i] << " ";
    cout << endl;
    // print(res,G);
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> G >> M;
        rep(i,G) cin >> H[i] >> D[i];
        printf("Case #%d: ", iCase++);
        solve();
    }
    return 0;
}