/**
*2017icpc沈阳站
*先求出树的重心，以重心为根深搜求每个节点对应的子树规模
*对应的子树规模大于等于k的节点为有效节点
*将有效节点连接起来的边为有效边
*有效边的条数即是问题的答案，等于有效节点的个数减一
*/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;

vector<int> g[maxn];
int sz[maxn], mv[maxn];
int n, k;

void dfs_size(int u, int fa){
    sz[u] = 1;
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(v != fa){
            dfs_size(v, u);
            sz[u] += sz[v];
        }
    }
}

void dfs_root(int u, int fa){
    mv[u] = n - sz[u];
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(v != fa){
            dfs_root(v, u);
            mv[u] = max(mv[u], sz[v]);
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &k);
        for(int i = 0; i <= n; i++){
            g[i].clear();
        }
        for(int i = 0; i < n - 1; i++){
            int a, b;
            scanf("%d%d", &a, &b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs_size(1, -1);
        dfs_root(1, -1);
        int root = 1;
        for(int i = 1; i <= n; i++){
            if(mv[i] < mv[root]){
                root = i;
            }
        }
        dfs_size(root, -1);
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(sz[i] >= k){
                cnt++;
            }
        }
        printf("%d\n", cnt - 1);
    }
    return 0;
}
