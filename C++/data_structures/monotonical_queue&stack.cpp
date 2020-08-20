#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
#define repr(i,n) for(int i = n; i > -1; --i) 
#define REP(i,start,end,step) for(int i = start; i < end; i += step) 
#define REPR(i,start,end,step) for(int i = start; i > end; i += step)
#define lowbit(x) ((x) & (-x))
//global variables
#define MAXN 10010
int N, K, A[MAXN];

//------------------MonotonicalQueue-starts----------------------
class MonotonicalQueue{
    int window, idx = 0;
    deque<pair<int,int>> que; // first: value, second: index
    int const&(*cmp)(int const&, int const&);
public:
    MonotonicalQueue(){}
    MonotonicalQueue(int W, int const&(*f)(int const&, int const&)):window(W),cmp(f){}
    void insert(int N){
        while(!que.empty() && cmp(que.back().first,N) == N) que.pop_back();
        que.push_back(make_pair(N,idx++));
        while(que.front().second <= idx - window) que.pop_front();
    }
    inline int get(){ return que.front().first; }
};
//------------------MonotonicalQueue-ends----------------------

/*
Monotonical Stack can also be used to implement offline RMQ algorithm.
Steps:
    1. sort the right point.
    2. insert N from 1 to r.
    3. binary search on the stack, the lower_bound of stack is the min / max
Time Complexity:
    Initialization: O(Q*logQ + N*logN)
*/

//------------------MonotonicalStack-starts----------------------
class MonotonicalStack{
    int idx = 0;
    deque<pair<int,int>> sta; // first: value, second: index
    int const&(*cmp)(int const&, int const&);
public:
    MonotonicalStack(){}
    MonotonicalStack(int const&(*f)(int const&, int const&)):cmp(f){}
    void insert(int N){
        while(!sta.empty() && cmp(sta.back().first,N) == N) sta.pop_front();
        sta.push_back(make_pair(N,idx++));
    }
};
//------------------MonotonicalStack-ends------------------------

int main(){
    cin >> N >> K;
    rep(i,N) cin >> A[i];
    MonotonicalQueue maxq(K,max), minq(K,min);
    rep(i,K){
        maxq.insert(A[i]);
        minq.insert(A[i]);
    }
    REP(i,K,N,1){
        maxq.insert(A[i]);
        minq.insert(A[i]);
        cout << maxq.get() << " " << minq.get() << endl;
    }
    MonotonicalStack maxs(max), mins(min);
    return 0;
}