#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define rep(i,n) for(int i = 0; i < n; ++i)
#define repr(i,n) for(int i = n; i > -1; --i) 
#define REP(i,start,end,step) for(int i = start; i < end; i += step) 
#define REPR(i,start,end,step) for(int i = start; i > end; i += step)
#define lowbit(x) ((x) & (-x))
typedef long long ll;
typedef unsigned long long ull;
template <typename T, size_t size>
void print(const T (&array)[size], int range){ //print(array,N);
    for(size_t i = 0; i < (uint)range; ++i) std::cout << array[i] << " ";
    cout << endl;
}
template<typename T>
void print(const T& t) { //print(vector);
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, ", "));
    cout << endl;
}
//global variables
#define mod 1000000000

//solve
pair<int,int> solve(const string &s){
    //init
    int x(1), y(1);
    int len = s.size(), i(0);
    stack<pair<int,int>> sp; //stack of pairs
    stack<int> sn; //stack of nums
    int num;
    ll xx,yy,xxx,yyy;
    //do things
    while(i < len){
        switch (s[i]){
        case 'N':
            if(--y == 0) y = mod; 
            break;
        case 'S':
            if(++y == mod + 1) y = 1;
            break;
        case 'W':
            if(--x == 0) x = mod;
            break;
        case 'E':
            if(++x == mod + 1) x = 1;
            break;
        case ')':
            num = sn.top();
            xxx = sp.top().fi; yyy = sp.top().se;
            xx = 1LL*num*(x-1) + xxx;
            yy = 1LL*num*(y-1) + yyy;
            sp.pop(); sn.pop();
            x = xx % mod; y = yy % mod;
            if(x <= 0) x += mod;
            if(y <= 0) y += mod;
            break;
        default: //numbers
            num = s[i]-'0';
            sp.push(mp(x,y));
            sn.push(num);
            x = 1; y = 1;
            i++;
            break;
        }
        i++;
    }
    //store results
    return mp(x,y);
}

int main(){
    std::ios::sync_with_stdio(false);
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        string program;
        cin >> program;
        pair<int,int> res = solve(program);
        printf("Case #%d: %d %d\n", iCase++, res.fi, res.se);
    }
    return 0;
}