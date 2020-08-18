#include <bits/stdc++.h>
using namespace std;
const int MAXQ = 1e5+2, MAXN = 1e5+2, MAXM = 1e5+2;
int N, q, A[MAXN], ans[MAXQ];

/*
If can transfer state from [l,r] to [l-1,r], [l+1,r], [l,r-1], [l,r+1] in O(N), MoArray is available.
Time Complexity:
    O(N*sqrt(N))
The queries should be offline and sorted: 
    1. if l is odd, r is sorted in ascending order.
    2. if l is even, r is sorted in descending order.
To modify:
    The add and del functions
*/

//---------------------MoArray-starts------------------------
class MoArray{
    vector<int> arr, ans, cnt;
    int l = 1, r = 0, cur = 0, size;
    inline void add(int p) {
        if (cnt[arr[p]] == 0) cur++;
        cnt[arr[p]]++;
    }
    inline void del(int p){
        cnt[arr[p]]--;
        if (cnt[arr[p]] == 0) cur--;
    }
public:
    MoArray(){}
    MoArray(const int A[], int N){
        size = N;
        for(int i = 1; i <= N; i++) arr[i] = A[i-1];
    }
    long long query(int ll, int rr){
        while (l < ll) del(l++);
        while (l > ll) add(--l);
        while (r < rr) add(++r);
        while (r > rr) del(r--);
        return cur;
    }
};
//---------------------MoArray-ends--------------------------

int sq;
struct query {
    int l, r, id;
    bool operator<(const query &o) const {
        if (l / sq != o.l / sq) 
            return l < o.l;
        if (l / sq & 1)
            return r < o.r;
        return r > o.r;
    }
} Q[MAXQ];

int main() {
    cin >> N;
    sq = sqrt(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    MoArray ma(A,N);
    cin >> q;
    for (int i = 0; i < q; ++i){
        cin >> Q[i].l >> Q[i].r;
        Q[i].id = i;
    }
    sort(Q, Q + q); // sort
    for (int i = 0; i < q; ++i){
        ans[Q[i].id] = ma.query(Q[i].l,Q[i].r);
    }
    for (int i = 0; i < q; ++i)
        printf("%d\n", ans[i]); // output based on id
    return 0;
}