#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 105;

int ar[maxn];
int ans = 0;

void dfs(int k, int t, int sum){
    if(k == 36){
        if(sum == 100){
            ans = max(ans, t);
        }
    }
    else{
        dfs(k + 1, t, sum);
        dfs(k + 1, t + 1, sum + ar[k]);
    }
}

int main()
{
    freopen("test.txt", "r", stdin);
    int n = 0, x, y;
    while(~scanf("%d%d", &x, &y)){
        if(y <= 20){
            ar[++n] = x;
        }
    }
    dfs(1, 0, 0);
    printf("%d\n", ans);
    return 0;
}
