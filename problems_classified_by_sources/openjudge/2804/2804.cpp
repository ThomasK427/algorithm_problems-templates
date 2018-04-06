#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int maxl = 15;

int trie[maxn][30], dict[maxn * maxl];
char str[maxn][maxl] = {"eh"};
char buf[maxl * 2], foreign[maxl];

int cnt = 0;

void insert(char* s, int id){
    int m = strlen(s);
    int root = 0;
    for(int i = 0; i < m; i++){
        int p = s[i] - 'a';
        if(!trie[root][p]){
            trie[root][p] = ++cnt;
        }
        root = trie[root][p];
    }
    dict[root] = id;
}

int search(char* s){
    int m = strlen(s);
    int root = 0;
    for(int i = 0; i < m; i++){
        int p = s[i] - 'a';
        if(!trie[root][p]){
            return 0;
        }
        root = trie[root][p];
    }
    return dict[root];
}

int main()
{
    memset(trie, 0, sizeof(trie));
    int n = 0;
    while(gets(buf) && strlen(buf)){
        sscanf(buf, "%s%s", str[++n], foreign);
        insert(foreign, n);
    }
    while(~scanf("%s", foreign)){
        puts(str[search(foreign)]);
    }
    return 0;
}
