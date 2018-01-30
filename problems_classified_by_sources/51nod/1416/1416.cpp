#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 55;

char g[maxn][maxn];
int vis[maxn][maxn];
int n, m;
int d[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int idx = 0;

inline bool check(int u, int v){
    return u >= 0 && u < n && v >= 0 && v < m;
}

bool dfs(int u, int v, int fu, int fv){
    vis[u][v] = 1;
    for(int i = 0; i < 4; i++){
        int x = u + d[i][0], y = v + d[i][1];
        if(check(x, y) && g[u][v] == g[x][y] && (x != fu || y != fv)){
            if(vis[x][y] == 1){
                return true;
            }
            else{
                if(dfs(x, y, u, v)){
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%s", g[i]);
    }
    memset(vis, 0, sizeof(vis));
    bool flag = false;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vis[i][j] == 0){
                if(dfs(i, j, -1, -1)){
                    flag = true;
                    break;
                }
            }
        }
        if(flag){
            break;
        }
    }
    if(flag){
        puts("Yes");
    }
    else{
        puts("No");
    }
    return 0;
}
