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
ll N;
int S;

//-------------function-starts---------------------
//-------------function-ends-----------------------

void solve(){
    //init
    deque<int> num;
    ll NN = N;
    while(NN > 0){
        num.push_front(NN % 10);
        NN /= 10;
    }
    num.push_front(0);
    int SUM = 0;
    stack<int> s;
    for(int i = 0; i < (int)num.size(); i++){
        SUM += num[i];
        s.push(num[i]);
        if(SUM > S){
            break;
        }
    }
    if(SUM <= S){
        cout << 0 << endl;
        return;
    } else {
        while(SUM > S){
            SUM -= s.top();
            s.pop();
            s.top()++;
            SUM++;
            while(s.top() == 10){
                SUM -= 10;
                s.pop();
                s.top()++;
            }
        }
    }
    ll final = 0;
    while(!s.empty()){
        int digit = num.size() - s.size();
        final += (ll)pow((ll)10,(ll)digit) * s.top();
        s.pop();
    }
    cout << final - N << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N >> S;
        solve();
    }
    return 0;
}