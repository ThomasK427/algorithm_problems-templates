#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;

bool vis[maxn];
vector<int> g[maxn];

void bfs(int src){
    queue<int> que;
    que.push(src);
    while(!que.empty()){
        int u = que.front();
        que.pop();
        vis[u] = true;
        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i];
            if(!vis[v]){
                que.push(v);
            }
        }
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    memset(vis, false, sizeof(vis));
    bfs(1);
    bool flag = true;
    for(int i = 1; i <= n; i++){
        flag = flag && vis[i];
    }
    if(flag && m == n){
        puts("FHTAGN!");
    }
    else{
        puts("NO");
    }
    return 0;
}

