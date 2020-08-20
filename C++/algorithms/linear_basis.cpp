#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100;


//--------------------linear-basis-starts------------------------
typedef unsigned long long ull;
ull p[64];
void insert(ull x){
    for (int k = 63; k >= 0; --k) {
        if (x >> k == 0)  continue;
        if (p[k] == 0) { 
            p[k] = x;
            break;
        }
        x ^= p[k]; 
    }
}
ull getmax(){
    int ans = 0;
    for (int i = 63; i >= 0; --i) if ((ans ^ p[i]) > ans) ans ^= p[i];
    return ans;
}
ull getmin(){
    for(int i = 0; i < 64; i++) if(p[i] != 0) return p[i];
    return 0;
}
//--------------------linear-basis-ends--------------------------

int main(){
    int X[MAXN];
    for(int i = 0; i < MAXN; i++)
        insert(X[i]);
    cout << getmax() << " " << getmin() << endl;
    return 0;
}