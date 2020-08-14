#include <bits/stdc++.h>
#define MAXN 400010
#define MAXQ 100010
#define ZERO 10e-6
using namespace std;
typedef long long lld;
int n,q;
int X[MAXN],Y[MAXN],Z[MAXQ];
int L[MAXN],R[MAXN];
pair<int,int> K[MAXQ];
lld A[3],B[3],C[3],M[3];
map<int,int> axis;

int main() {
    int t;
    scanf("%d",&t);
    for(auto round=1;round<=t;++round) {
        scanf("%d%d",&n,&q);
        scanf("%d%d%d%d%d%d",&X[0],&X[1],&A[0],&B[0],&C[0],&M[0]);
        scanf("%d%d%d%d%d%d",&Y[0],&Y[1],&A[1],&B[1],&C[1],&M[1]);
        scanf("%d%d%d%d%d%d",&Z[0],&Z[1],&A[2],&B[2],&C[2],&M[2]);
        for(int i=2;i<n;i++) {
            X[i] = ((lld)A[0]*X[i-1]+(lld)B[0]*X[i-2]+C[0])%M[0];
            Y[i] = ((lld)A[1]*Y[i-1]+(lld)B[1]*Y[i-2]+C[1])%M[1];
        }
        for(int i=2;i<q;++i) {
            Z[i] = ((lld)A[2]*Z[i-1]+(lld)B[2]*Z[i-2]+C[2])%M[2];
        }
        axis.clear();
        for(int i=0;i<n;++i) {
            L[i] = min(X[i],Y[i]);
            R[i] = max(X[i],Y[i])+1;
            axis[L[i]] -= 1;
            axis[R[i]] += 1;
        }
        for(int i=0;i<q;++i) {
            K[i].first = Z[i];
            K[i].second = i+1;
        }
        sort(K,K+q);
        int ptr = 0, grps = 0, prev = 0;
        lld total = 0;
        lld ans = 0;
        for(auto it = axis.end();it!=axis.begin();) {
            it--;
            lld interL = (lld)(prev-it->first)*grps;
            while(ptr<q && K[ptr].first-total<interL) {
                ans += (lld)(prev-(K[ptr].first-total)/grps)*K[ptr].second;
                ptr++;
            }
            if(ptr==q) break;
            prev = it->first;
            grps += it->second;
            total += interL;
        }
        printf("Case #%d: %lld\n",round,ans);
    }
}