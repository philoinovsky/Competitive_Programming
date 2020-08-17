#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001000

//-------------Euler-Prime-Sieve-starts--------------
bool isnp[MAXN];
vector<int> primes;
void prime_init(int n){
    for (int i = 2; i <= n; i++) {
        if (!isnp[i])
            primes.push_back(i);
        for (int p : primes) {
            if (p * i > n) break;
            isnp[p * i] = 1;
            if (i % p == 0) break;
        }
    }
}
//-------------Euler-Prime-Sieve-ends----------------

int main(){
    prime_init(10000);
    for(auto e: primes) cout << e << " ";
    cout << endl;
    return 0;
}