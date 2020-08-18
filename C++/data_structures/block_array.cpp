#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+2;
int N, M, A[MAXN];
/*
Time Complexity:
    1. single point update O(1)
    2. interval update O(sqrt(N))
    3. single point query O(1)
    4. interval query O(sqrt(N))
Space Complexity:
    O(N) (3*N + 4*sqrt(N))
Indexing:
    1. range from 1 to N + 1
*/

//--------------------BlockArray-starts--------------------
class BlockArray {
    vector<int> st, ed, bel, size, sum, arr, mark;
public:
    BlockArray(){}
    BlockArray(const int A[], int n){
        int sq = sqrt(n);
        st.resize(sq+1);
        ed.resize(sq+1);
        bel.resize(n+1);
        size.resize(sq+1);
        sum.resize(n+1);
        arr.resize(n+1);
        mark.resize(sq+1);
        // ith block starts with st[i], ends with ed[i]
        for(int i = 1; i <= sq; i++){
            st[i] = n / sq * (i - 1) + 1; 
            ed[i] = n / sq * i;
        }
        ed[sq] = n;
        for(int i = 1; i <= sq; ++i)
            for (int j = st[i]; j <= ed[i]; ++j)
                bel[j] = i;  // j belongs to ith block
        for(int i = 1; i <= sq; ++i)
            size[i] = ed[i] - st[i] + 1;
        for(int i = 1; i <= sq; i++)
            for(int j = st[i]; j <= ed[i]; j++)
                sum[i] += A[j-1];
        for(int i = 1; i <= n; i++)
            arr[i] = A[i+1];
    }
    void update(int l, int r, int d){
        if(bel[l] == bel[r]){
            for(int i = l; i <= r; i++){
                arr[i] += d;
                sum[bel[i]] += d;
            }
        } else {
            for(int i = l; i <= ed[bel[l]]; i++){
                arr[i] += d;
                sum[bel[i]] += d;
            }
            for(int i = st[bel[r]]; i <= r; i++){
                arr[i] += d;
                sum[bel[i]] += d;
            }
            for(int i = bel[l] + 1; i < bel[r]; i++)
                mark[i] += d;
        }
    }
    long long query(int l, int r){
        long long res = 0;
        if(bel[l] == bel[r]){
            for(int i = l; i <= r; i++)
                res += arr[i] + mark[bel[i]];
        } else {
            for(int i = l; i <= ed[bel[l]]; i++)
                res += arr[i] + mark[bel[i]];
            for(int i = st[bel[r]]; i <= r; i++)
                res += arr[i] + mark[bel[i]];
            for(int i = bel[l] + 1; i < bel[r]; i++)
                res += sum[i] + mark[i] * size[i];
        }
        return res;
    }
};
//--------------------BlockArray-ends--------------------

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> A[i];
    BlockArray ba(A,N);
    for(int i = 0; i < M; i++){
        char o;
        int l, r, d;
        cin >> o >> l >> r >> d;
        if(o == 'M'){
            ba.update(l,r,d);
        } else {
            cout << ba.query(l,r) << endl;
        }
    }
    return 0;
}