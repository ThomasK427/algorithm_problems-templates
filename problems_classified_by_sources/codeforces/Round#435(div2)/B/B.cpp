#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 100005;

int degree[maxn];
int c[maxn];
vector<int> g[maxn];
int cnt1 = 0, cnt2 = 0, n;

void dfs(int k, int fa, int color){
    c[k] = color;
    if(color == 0){
        cnt1++;
    }
    else{
        cnt2++;
    }
    for(int i = 0; i < g[k].size(); i++){
        if(g[k][i] != fa){
            dfs(g[k][i], k, 1 - color);
        }
    }
}

int main()
{
    //freopen("test.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
    dfs(1, -1, 0);
    LL ans = 0;
    for(int i = 1; i <= n; i++){
        if(c[i] == 0){
            ans += cnt2 - degree[i];
        }
    }
    printf("%lld\n", ans);
    return 0;
}
