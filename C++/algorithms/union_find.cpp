#include <iostream>
using namespace std;
const int MAXN = 1e6+10;

//-------------------union-find-starts------------------------------
//RANK can be used same time with compress path, lead to O(n)
class UnionFindSet {
public:
    int fa[MAXN], RANK[MAXN];
    inline void init(int n){ for (int i = 1; i <= n; ++i){ fa[i] = i; RANK[i] = 1; } }
    inline void merge(int i, int j){
        int x = find(i), y = find(j);    //find two roots first
        (RANK[x] <= RANK[y]) ? (fa[x] = y) : (fa[y] = x);
        if (RANK[x] == RANK[y] && x != y) RANK[y]++; //if same depth but root different, new root depth +1
    }
    int find(int x){ return (x == fa[x]) ? x : find(fa[x]); }
};
//-------------------union-find-ends--------------------------------

int main(){
    int N, M, P, X, Y;
    cin >> N >> M >> P;
    UnionFindSet ufs;
    ufs.init(N);
    for(int i = 0; i < M; i++) {
        cin >> X >> Y;
        ufs.merge(X, Y);
    }
    for(int i = 0; i < P; i++) {
        cin >> X >> Y;
        string res = ufs.find(X) == ufs.find(Y) ? "Yes" : "No";
        cout << res << endl;
    }
    return 0;
}