#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define rep(i,n) for(int i = 0; i < n; ++i)
#define repr(i,n) for(int i = n; i > -1; --i) 
#define REP(i,start,end,step) for(int i = start; i < end; i += step) 
#define REPR(i,start,end,step) for(int i = start; i > end; i += step)
#define lowbit(x) ((x) & (-x))
typedef long long ll;
typedef unsigned long long ull;
template <typename T, size_t size> void print(const T (&array)[size], int range){ //print(array,N);
    for(size_t i = 0; i < (uint)range; ++i) std::cout << array[i] << " "; 
    cout << endl;}
template<typename T> void print(const T& t) { //print(vector);
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, ", "));}
//global variables
#define MAXN 2001000
int N,K;
string S[MAXN];

//----------------------Trie-start------------------------
struct TrieNode { 
    struct TrieNode *children[26];
    int cnt[26] = {0};
    bool isEndOfWord = false; 
};
struct TrieNode *getNode() { 
    struct TrieNode *pNode =  new TrieNode;
    for (int i = 0; i < 26; i++)
        pNode->children[i] = NULL;
    return pNode;
} 
void insert(struct TrieNode *root, string key) {
    struct TrieNode *pCrawl = root; 
    for (int i = 0; i < (int)key.length(); i++) { 
        int index = key[i] - 'A';
        (pCrawl->cnt[index])++;
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
        pCrawl = pCrawl->children[index]; 
    }
    pCrawl->isEndOfWord = true; 
} 
bool search(struct TrieNode *root, string key) {
    struct TrieNode *pCrawl = root; 
    for (int i = 0; i < (int)key.length(); i++) { 
        int index = key[i] - 'A'; 
        if (!pCrawl->children[index]) 
            return false; 
        pCrawl = pCrawl->children[index]; 
    } 
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
}
//-----------------------Trie-end-------------------------

int solve(){
    struct TrieNode *root = getNode();
    rep(i,N) insert(root,S[i]);
    int ans = 0;
    queue<TrieNode *> q;
    q.push(root);
    while (!q.empty()){
        TrieNode *cur = q.front();
        q.pop();
        rep(i,26){
            if(cur->children[i] != NULL){
                q.push(cur->children[i]);
                ans += cur->cnt[i] / K;
            }
        }
    }
    return ans;
}

int main(){
    int T, iCase(1);
    scanf("%d",&T);
    while(T--){
        //read params to global variables
        scanf("%d%d",&N,&K);
        rep(i,N) cin >> S[i];
        printf("Case #%d: %d\n", iCase++, solve());
    }
    return 0;
}