#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;

char u[maxn], v[maxn], w[maxn];

int Find(int a, int b, char ch){
    for(int i = a; i <= b; i++){
        if(v[i] == ch){
            return i;
        }
    }
}

void dfs(int a1, int b1, int a2, int b2, int a3, int b3){
    if(a1 > b1){
        return;
    }
    int p = Find(a2, b2, u[a1]);
    int l = p - a2, r = b2 - p;
    w[b3] = u[a1];
    dfs(a1 + 1, a1 + l, a2, p - 1, a3, a3 + l - 1);
    dfs(a1 + l + 1, b1, p + 1, b2, a3 + l, b3 - 1);
}

int main()
{
    while(~scanf("%s%s", u, v)){
        int n = strlen(u);
        dfs(0, n - 1, 0, n - 1, 0, n - 1);
        w[n] = '\0';
        puts(w);
    }
    return 0;
}
