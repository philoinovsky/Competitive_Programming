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
#define MAXN 100010
int N, K, M[MAXN], diff[MAXN], maxdiff;

int single_insert_num(int mm, int d){
    int cnt(0), tmp(0);
    while (tmp < mm){
        cnt++;
        tmp += d;
    }
    return cnt - 1;
}

int total_insert_num(int d){
    int res(0);
    rep(i, N-1){
        res += single_insert_num(diff[i],d);
    }
    return res;
}

int solve(){
    rep(i,N){ diff[i] = M[i+1] - M[i]; }
    maxdiff = *max_element(diff,diff+N-1);
    int low(1), mid, high(maxdiff), res(maxdiff), kk;
    while (low <= high){
        mid = (low + high) / 2;
        kk = total_insert_num(mid);
        if(kk > K){
            low = mid + 1;
        } else {
            res = mid;
            high = mid - 1;
        }
    }
    return res;
}

int main(){
    int T, iCase(1);
    scanf("%d",&T);
    while(T--){
        //read params to global variables
        scanf("%d%d",&N,&K);
        rep(i,N){scanf("%d",&M[i]);}
        printf("Case #%d: %d\n", iCase++,solve());
    }
    return 0;
}