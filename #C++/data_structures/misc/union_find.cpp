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

//-------------------union-find(generic)-starts------------------------------
template<typename T>
class UnionFindSet
{
public:
    UnionFindSet(size_t size)
    : m_parent(size)
    , m_rank(size, 1)
    , m_disjoint_cnt(size)
    {
        for (size_t i = 0; i < size; ++i)
            m_parent[i] = i;
    }

    void merge(T i, T j) noexcept
    {
        const T& x = find(i), y = find(j);
        if (m_rank[x] <= m_rank[y])
            m_parent[x] = y;
        else
            m_parent[y] = x;
        if (m_rank[x] == m_rank[y] && x != y)
            m_rank[y]++;
        if (x != y)
            m_disjoint_cnt--;
    }
    
    inline const T& find(const T& x) const
    {
        return (x == m_parent[x]) ? x : find(m_parent[x]);
    }

    inline size_t get_disjoint_cnt() const
    {
        return m_disjoint_cnt;
    }
private:
    vector<T> m_parent, m_rank;
    size_t m_disjoint_cnt;
};
//-------------------union-find(generic)-ends--------------------------------

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