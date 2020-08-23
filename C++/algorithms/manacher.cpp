#include<bits/stdc++.h>
using namespace std;

//-------------------------Manacher-starts----------------------------
char s[1000], s_new[2000];
int p[2000];
int Init(){
    int len = strlen(s);
    s_new[0] = '$';
    s_new[1] = '#';
    int j = 2;
    for (int i = 0; i < len; i++){
        s_new[j++] = s[i];
        s_new[j++] = '#';
    }
    s_new[j++] = '^';  // 别忘了哦
    s_new[j] = '\0';   // 这是一个好习惯
    return j;  // 返回 s_new 的长度
}
int Manacher() {
    int len = Init(), max_len = -1, id, mx = 0;
    for (int i = 1; i < len; i++) {
        if (i < mx) {
            p[i] = min(p[2 * id - i], mx - i);// 需搞清楚上面那张图含义，mx 和 2*id-i 的含义
        } else {
            p[i] = 1;
        } 
        while (s_new[i - p[i]] == s_new[i + p[i]])  // 不需边界判断，因为左有 $，右有 ^
            p[i]++;
        // 我们每走一步 i，都要和 mx 比较，我们希望 mx 尽可能的远，
        // 这样才能更有机会执行 if (i &lt; mx)这句代码，从而提高效率
        if (mx < i + p[i]) {
            id = i;
            mx = i + p[i];
        }
        max_len = max(max_len, p[i] - 1);
    }
    return max_len;
}
//-------------------------Manacher-ends------------------------------

int main() {
    while (printf("请输入字符串：")) {
        scanf("%s", s);
        printf("最长回文长度为 %d\n\n", Manacher());
    }
    return 0;
}