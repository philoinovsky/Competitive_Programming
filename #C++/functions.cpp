#include <bits/stdc++.h>
using namespace std;

const int N = 0x8012;

inline bool startswith(const string &s1, const string &s2){ return s1.rfind(s2, 0) == 0; }

//------------------------quick-pow-start--------------------------------
//with mod a^b
int fastpow(int a, int b, int MOD){
    int ret(1);
    while(b){
        if (b & 1) ret = 1LL*ret*a % MOD;
        a = 1LL*a*a % MOD;
        b >>= 1;
    }
    return ret;
}
//--------------------------quick-pow-end--------------------------------

//-------------------------mod-reverse---------------------------------
long long exgcd(long long a, long long b, long long &x, long long &y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    } else {
        long long _gcd = exgcd(b, a%b, x, y);
        long long tmp = x - (a/b) * y;
        x = y; y = tmp;
        return _gcd;
    }
}

int exgcd(int a, int b, int &x, int &y){
    if(b==0){
        x = 1; y = 0;
        return a;
    } else {
        int _gcd = exgcd(b, a%b, x, y);
        int tmp = x - (a/b)*y;
        x = y; y = tmp;
        return _gcd;
    }
}

//a*x=1(mod b)
int mod_inverse(int a,int MOD){
    int d,x,y;
    d = exgcd(a,MOD,x,y);
    if(d == 1) return (x % MOD + MOD) % MOD;
    else return -1;
}

//Fermat's Little Theorem
inline int mod_inverse(int a, int MOD) { return fastpow(a,MOD-2,MOD); }
//--------------------mod-reverse-end--------------------------

//-------------------------combination-starts------------------------
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
//-------------------------combination-ends----------------------------

//-------------------------combination-backtracking-starts--------------
void combination(vector<long long> &res, long long cur, int start, int cnt0, int cnt1, int cnt2, bool repeat){
    if(start == 3*N){
        res.push_back(cur);
    } else {
        if(cnt0 < N) combination(res,cur,start+1,cnt0+1,cnt1,cnt2,repeat);
        if(cnt1 < N) combination(res,cur|(1<<(2*start)),start+1,cnt0,cnt1+1,cnt2,repeat);
        if((cnt1||repeat)&&cnt2<N) combination(res,cur|(2<<(2*start)),start+1,cnt0,cnt1,cnt2+1,repeat);
    }
}
//-------------------------combination-backtracking-ends----------------

//----------------discretization-starts--------------------------------
void distritize(vector<int> & O, vector<int> & R){
    vector<int> tmp = O;
    sort(O.begin(),O.end());
    int N = unique(O.begin(),O.end()) - O.begin();
    for(int i = 0; i < tmp.size(); i++)
        R[i] = lower_bound(O.begin(),O.end(),tmp[i]) - O.begin() + 1;
    O.swap(tmp);
}
//----------------discretization-starts--------------------------------

//----------------Chinese-Remainder-Theorem-starts------------------------
inline long long CRT(long long mod[], long long remainder[], int len){
    long long p = 1, x = 0;
    for(int i = 0; i < len; i++) p *= mod[i];
    for(int i = 0; i < len; i++){
        long long r = p / mod[i];
        x += (remainder[i] * r * mod_inverse(r, mod[i])) % p;
    }
    return x % p;
}
//----------------Chinese-Remainder-Theorem-starts------------------------


int main(){
    return 0;
}