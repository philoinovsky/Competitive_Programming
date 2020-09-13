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

ll getpre(ll n){
    int cnt = 0;
    int num[20] = {0};
    do{
        num[cnt++] = n % 10;
        n /= 10;
    } while (n);
    repr(i,cnt-1){
        if(num[i]&1){
            num[i]--;
            repr(j,i-1) num[j] = 8;
            break;
        }
    }
    ll res = 0;
    repr(i,cnt-1){
        res += num[i];
        res *= 10;
    }
    res /= 10;
    return res;
}

ll getpost(ll n){
    int cnt = 0;
    int num[20] = {0};
    bool carry = false;
    int flag_digit = -1;
    do{
        num[cnt++] = n % 10;
        n /= 10;
    } while (n);
    rep(i,cnt+1){
        if(carry){
            if(num[i]==9){
                num[i] = 0;
                continue;
            } else {
                num[i]++;
                flag_digit = i;
                carry = false;
            }
        }
        if(num[i] & 1){
            if(num[i] == 9){
                num[i] = 0;
                carry = true;
                continue;
            } else {
                num[i]++;
                flag_digit = i;
            }
        }
    }
    ll res = 0;
    repr(i,cnt){
        if(i >= flag_digit)
            res += num[i];
        res *= 10;
    }
    res /= 10;
    return res;   
}

int main(){
    int T;
    int iCase = 0;
    scanf("%d",&T);
    while(T--){
        iCase++;
        ll n;
        scanf("%lld",&n);
        printf("Case #%d: %lld\n", iCase, min(n-getpre(n),getpost(n)-n));
    }
    return 0;
}