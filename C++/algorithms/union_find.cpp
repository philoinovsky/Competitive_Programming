#define MAXN 1000

int fa[MAXN];
inline void init(int n){
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
}

inline void merge(int i, int j){
    fa[find(i)] = find(j);
}

int find(int x){
    return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

//initialization
//rank can be used same time with compress path, lead to O(n)
int fa[MAXN];
int rank[MAXN];
inline void init(int n){
    for (int i = 1; i <= n; ++i){
        fa[i] = i;
        rank[i] = 1;
    }
}
inline void merge(int i, int j){
    int x = find(i), y = find(j);    //先找到两个根节点
    if (rank[x] <= rank[y])
        fa[x] = y;
    else
        fa[y] = x;
    if (rank[x] == rank[y] && x != y)
        rank[y]++;                   //如果深度相同且根节点不同，则新的根节点的深度+1
}
int find(int x){
    return x == fa[x] ? x : find(fa[x]);
}




