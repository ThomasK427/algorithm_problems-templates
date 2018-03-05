#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 100005;

vector<int> g[maxn];
int d[maxn];

void dfs(int node, int k){
    d[k] ^= 1;
    for(int i = 0; i < g[node].size(); i++){
        dfs(g[node][i], k + 1);
    }
}

int main()
{
    int n, p;
    scanf("%d", &n);
    for(int i = 2; i <= n; i++){
        scanf("%d", &p);
        g[p].push_back(i);
    }
    memset(d, 0, sizeof(d));
    dfs(1, 0);
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += d[i];
    }
    printf("%d\n", ans);
    return 0;
}
