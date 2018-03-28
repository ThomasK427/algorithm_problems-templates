#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;

vector<int> g[maxn];
int ans[maxn];
int c = 0;

void dfs(int u, int k){
    c = max(c, k);
    if(g[u].size() == 0){
        ans[k]++;
    }
    for(int i = 0; i < g[u].size(); i++){
        dfs(g[u][i], k + 1);
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        int id, k;
        scanf("%d%d", &id, &k);
        for(int j = 0; j < k; j++){
            int x;
            scanf("%d", &x);
            g[id].push_back(x);
        }
    }
    dfs(1, 1);
    for(int i = 1; i <= c; i++){
        printf("%d%c", ans[i], i == c ? '\n': ' ');
    }
    return 0;
}
