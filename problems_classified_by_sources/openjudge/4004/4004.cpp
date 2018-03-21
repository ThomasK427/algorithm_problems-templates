#include <bits/stdc++.h>
using namespace std;
const int maxn = 25;

int ar[maxn];
int n, t, ans = 0;

void dfs(int k, int s){
    if(k == n){
        if(s == t){
            ans++;
        }
    }
    else{
        dfs(k + 1, s);
        dfs(k + 1, s + ar[k]);
    }
}

int main()
{
    scanf("%d%d", &n, &t);
    for(int i = 0; i < n; i++){
        scanf("%d", ar + i);
    }
    dfs(0, 0);
    printf("%d\n", ans);
    return 0;
}
