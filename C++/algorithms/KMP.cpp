#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+10;
string S, P;

/* 
1. This function gemerate Partial Match Table (PMT) fot the pattern P, which takes O(M) time
2. pmt[i] stands for the largest match which: p[0] to p[pmt[i]] == p[i-pmt[i]] to p[i] 
*/

//-----------------------KMP-starts-----------------------
int pmt[MAXN];
bool pmtflag = false;
void generate_pmt(string &p, int pmt[]){
    pmt[0] = 0;
    int j = 0, M = p.length();
    for (int i = 1; i < M; i++) {
        while (p[i] != p[j] && j > 0)
            j = pmt[j - 1];
        if (p[i] == p[j])
            j++;
        pmt[i] = j;
    }
}
vector<int> KMP(string &S, string &P){
    if(!pmtflag) generate_pmt(P, pmt);
    int j = 0, N = S.length();
    for (int i = 0; i < N; ++i) {
        while (S[i] != P[j] && j > 0)
            j = pmt[j - 1];
        if (S[i] == P[j])
            j++;
        if (j == P.length()) {
            cout << i - j + 2 << endl;
            j = pmt[j - 1];
        }
    }
}
//-----------------------KMP-ends-----------------------

//in total takes O(N + M) to find all matches of pattern P in string S
int main(){
    cin >> S >> P;
    vector<int> res = KMP(S,P);
    for(auto e: res){
        cout << "pattern matches at position " << e << endl;
    }
    return 0;
}