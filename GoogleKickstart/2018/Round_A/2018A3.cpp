#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define rep(i,n) for(uint i = 0; i < n; ++i)
#define repr(i,n) for(uint i = n; i > -1; --i) 
#define REP(i,start,end,step) for(uint i = start; i < end; i += step) 
#define REPR(i,start,end,step) for(int i = start; i > end; i += step)
#define lowbit(x) ((x) & (-x))
#define SEED 13331
typedef long long ll;
typedef unsigned long long ull;
ull hashdict[1000100];
int A,B,C,D,L,cnt;
uint N;
char S1, S2;
vector<string> dict;

ull gethash(int a[], char start, char end){
    ull res = 0;
    res = start*SEED + end;
    rep(i,26){ res = res*SEED + a[i]; }
    return res;
}

void solve(){
    //init
    int dictsize;
    cnt = 0;
    //
    vector<int> X(N);
    string text;
    text.resize(N);
    X[0] = text[0] = S1; X[1] = text[1] = S2;
    REP(i,2,N,1){
        X[i] = ((ll)A*X[i-1] + (ll)B*X[i-2] + C) % D;
        text[i] = char('a' + X[i] % 26);
    }
    //
    auto comp = [](const string &a, const string &b){ return a.size() < b.size(); };
    sort(dict.begin(),dict.end(),comp);
    //do things
    uint last = 0;
    for(string &e: dict){
        if(e.size() > text.size()) break;
        if(e.size() != last){
            //init the hash
            last = e.size();
            dictsize = N-last+1;
            //first element
            int a[26] = {0};
            REP(j,1,e.size()-1,1){ a[text[j]-'a']++; }
            hashdict[0] = gethash(a,text[0],text[e.size()-1]);
            //sliding window
            REP(i,1,N-last+1,1){
                if(e.size() > 2){
                    a[text[i]-'a']--;
                    a[text[i+e.size()-2]-'a']++;
                }
                hashdict[i] = gethash(a,text[i],text[i+e.size()-1]);
            }
            sort(hashdict,hashdict+dictsize);
        }
        //find the hash
        int b[26] = {0};
        REP(i,1,e.size()-1,1){
            b[e[i]-'a']++;
        }
        ull curhash = gethash(b,e[0],e[e.size()-1]);
        if(binary_search(hashdict,hashdict+dictsize,curhash)){
            cnt++;
        }
    }
}

int main(){
    int T;
    int iCase = 0;
    scanf("%d",&T);
    while(T--){
        iCase++;
        scanf("%d",&L);
        dict.resize(L);
        for(string &word: dict){ cin >> word; }
        cin >> S1 >> S2 >> N >> A >> B >> C >> D;
        solve();
        printf("Case #%d: %d\n", iCase, cnt);
    }
    return 0;
}