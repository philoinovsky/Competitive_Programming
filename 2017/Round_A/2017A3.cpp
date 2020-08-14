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
template <typename T, size_t size> void print(const T (&array)[size], int range){ //print(array,N);
    for(size_t i = 0; i < (uint)range; ++i) std::cout << array[i] << " "; 
    cout << endl;
}
template<typename T> void print(const T& t) { //print(vector);
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, " "));
    cout << endl;
}
//global variables
#define MAXN 2000
int N, X[MAXN], Y[MAXN], Z[MAXN], R[MAXN], A[MAXN][3];

int solve(){
    //init
    pair<int*, int*> Xminmax = minmax_element(X,X+N);
    pair<int*, int*> Yminmax = minmax_element(Y,Y+N);
    pair<int*, int*> Zminmax = minmax_element(Z,Z+N);
    int Xmin = *Xminmax.fi, Xmax = *Xminmax.se;
    int Ymin = *Yminmax.fi, Ymax = *Yminmax.se;
    int Zmin = *Zminmax.fi, Zmax = *Zminmax.se;
    int dX = Xmax - Xmin, dY = Ymax - Ymin, dZ = Zmax - Zmin;
    if(dY > dX && dY >= dZ) {
        swap(X,Y); swap(Xminmax,Yminmax); swap(dX,dY); swap(Xmin,Ymin); swap(Xmax,Ymax);
    } else if (dZ > dX && dZ > dY) {
        swap(X,Z); swap(Xminmax,Zminmax); swap(dX,dZ); swap(Xmin,Zmin); swap(Xmax,Zmax);
    }
    rep(i,N) {
        A[i][0] = X[i]; 
        A[i][1] = Y[i]; 
        A[i][2] = Z[i]; 
    }
    auto comp0 = [](const void *arg1, const void *arg2)->int{
        int const *lhs = static_cast<int const*>(arg1);
        int const *rhs = static_cast<int const*>(arg2);
        return lhs[0] < rhs[0] ? -1 : 1;
    };
    std::qsort(A, N, sizeof(*A), comp0); // sort on X ascendingly
    //do things
    int l = dX / 2, r = dX, K;  // dX / 2 or (dX + 1)/2 ?
    while (l != r) {
        K = (l + r + 1) / 2;
        int up = 0, down = N - 1;
        int Yminup = Ymax, Ymaxup = Ymin, Zminup = Zmax, Zmaxup = Zmin;
        while(A[up][0] < Xmax - K) { // < or <= ?
            Yminup = min(Yminup,A[up][1]);
            Ymaxup = max(Ymaxup,A[up][1]);
            Zminup = min(Zminup,A[up][2]);
            Zmaxup = max(Zmaxup,A[up][2]);
            up++;
        }
        int Ymindown = Ymax, Ymaxdown = Ymin, Zmindown = Zmax, Zmaxdown = Zmin;
        while(A[down][0] > Xmin + K) {
            Ymindown = min(Ymindown,A[down][1]);
            Ymaxdown = max(Ymaxdown,A[down][1]);
            Zmindown = min(Zmindown,A[down][2]);
            Zmaxdown = max(Zmaxdown,A[down][2]);
            down--;
        }
        bool YbigZsmall = 0, YsmallZbig = 0, YbigZbig = 0, YsmallZsmall = 0;
        bool Yupbig, Yupsmall, Zupbig, Zupsmall, Ydownbig, Ydownsmall, Zdownbig, Zdownsmall;
        Yupbig = Yminup >= Ymax - K;
        Yupsmall = Ymaxup <= Ymin + K;
        Zupbig = Zminup >= Zmax - K;
        Zupsmall = Zmaxup <= Zmin + K;
        Ydownbig = Ymindown >= Ymax - K;
        Ydownsmall = Ymaxdown <= Ymin + K;
        Zdownbig = Zmindown >= Zmax - K;
        Zdownsmall = Zmaxdown <= Zmin + K;
        bool fail = !(Yupbig || Yupsmall) || 
                    !(Zupbig || Zupsmall) || 
                    !(Ydownbig || Ydownsmall) || 
                    !(Zdownbig || Zdownsmall);
        if(fail){ r = K - 1; continue; }
        YbigZsmall = (Yupbig && Zupsmall) || (Ydownbig && Zdownsmall);
        YsmallZbig = (Zupbig && Yupsmall) || (Zdownbig && Ydownsmall);
        YbigZbig = (Yupbig && Zupbig) || (Ydownbig && Zdownbig);
        YsmallZsmall = (Yupsmall && Zupsmall) || (Ydownsmall && Zdownsmall);
        REP(i,up,down+1,1){
            bool Ybig = A[i][1] > Ymin + K;
            bool Ysmall = A[i][1] < Ymax - K;
            bool Zbig = A[i][2] > Zmin + K;
            bool Zsmall = A[i][2] < Zmax - K;
            if(Ybig && Zbig){
                if(!YbigZbig) { fail = true; break; }
                YbigZsmall = YsmallZbig = false;
            } else if (Ybig && Zsmall) {
                if(!YbigZsmall) { fail = true; break; }
                YbigZbig = YsmallZsmall = false;
            } else if (Ysmall && Zbig) {
                if(!YsmallZbig) { fail = true; break; }
                YbigZbig = YsmallZsmall = false;                
            } else if (Ysmall && Zsmall) {
                if(!YsmallZbig) { fail = true; break; }
                YbigZsmall = YsmallZbig = false;                
            } else if (Ybig) {
                if(!(YbigZbig || YbigZsmall)){ fail = true; break; }
            } else if (Ysmall) {
                if(!(YsmallZsmall || YsmallZbig)){ fail = true; break; }                
            } else if (Zbig) {
                if(!(YsmallZbig || YbigZbig)){ fail = true; break; }
            } else if (Zsmall) {
                if(!(YsmallZsmall || YbigZsmall)){ fail = true; break; }
            }
        }
        if(fail){ 
            r = K - 1; continue; 
        } else {
            l = K;
        }
    }
    //store results
    return K;
}

int main(){
    int T, iCase(1);
    cin >> T;
    while(T--){
        //read params to global variables
        cin >> N;
        rep(i,N) cin >> X[i] >> Y[i] >> Z[i] >> R[i];
        printf("Case #%d: %d\n", iCase++, solve());
    }
    return 0;
}