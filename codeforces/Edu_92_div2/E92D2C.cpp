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
//global variables
string S;

struct combinations{
    typedef vector<int> combination_t;
    combinations(int N, int R):completed(N<1||R>N),generated(0), N(N), R(R){
        for (int c = 1; c <= R; ++c) curr.push_back(c);
    }
    bool completed;
    int generated;
    combination_t next() {
        combination_t ret = curr;
        completed = true;
        for (int i = R - 1; i >= 0; --i) if (curr[i] < N - R + i + 1) {
            int j = curr[i] + 1;
            while (i <= R-1) curr[i++] = j++;
            completed = false;
            ++generated;
            break;
        }
        return ret;
    }
private:
    int N, R;
    combination_t curr;
};
//-------------function-starts---------------------
//-------------function-ends-----------------------
void solve(){
    int cnt[10] = {0};
    rep(i,S.length())
        cnt[S[i]-'0']++;
    int MAX = 0, idx = -1;
    rep(i,10)if(cnt[i] > MAX){
        MAX = cnt[i];
        idx = i;
    }
    vector<char> candidates;
    rep(i,10) if(cnt[i]>MAX/2) candidates.push_back(i+'0');
    combinations com(candidates.size(),2);
    while(!com.completed){
        vector<int> next = com.next();
        int a = next[0];
        int b = next[1];
        int index = 0;
        char target = candidates[0];
        while(index < S.size()){
            if(target)
        }
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        //read params to global variables
        cin.get();
        cin >> S;
        solve();
    }
    return 0;
}