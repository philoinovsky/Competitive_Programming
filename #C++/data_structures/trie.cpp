#include <bits/stdc++.h>
using namespace std;

//########################################################
//----------------------Trie-start------------------------
struct TrieNode { 
    struct TrieNode *children[26];
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
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
        pCrawl = pCrawl->children[index]; 
    }
    pCrawl->isEndOfWord = true; 
} 
bool search(struct TrieNode *root, string key) {
    struct TrieNode *pCrawl = root; 
    for (int i = 0; i < (int)key.length(); i++) { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            return false; 
        pCrawl = pCrawl->children[index]; 
    } 
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
}
//-----------------------Trie-end-------------------------
//########################################################

//#######################example##########################
// Driver 
int main() {
    // Input keys (use only 'a' through 'z' 
    // and lower case) 
    string keys[] = {"the", "a", "there", 
                    "answer", "any", "by", 
                     "bye", "their" }; 
    int n = sizeof(keys)/sizeof(keys[0]); 
    struct TrieNode *root = getNode(); 
    // Construct trie 
    for (int i = 0; i < n; i++) 
        insert(root, keys[i]); 
    // Search for different keys 
    search(root, "the")? cout << "Yes\n" : 
                         cout << "No\n"; 
    search(root, "these")? cout << "Yes\n" : 
                           cout << "No\n"; 
    return 0; 
} 