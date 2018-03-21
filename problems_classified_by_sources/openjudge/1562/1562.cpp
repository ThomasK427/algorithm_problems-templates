#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;

char g[maxn][maxn];
bool used[maxn][maxn];
int m, n;

bool check(int x, int y){
    return x >= 0 && x < m && y >= 0 && y < n && !used[x][y] && g[x][y] == '@';
}

void dfs(int x, int y){
    used[x][y] = true;
    for(int dx = -1; dx <= 1; dx++){
        for(int dy = -1; dy <= 1; dy++){
            if(dx == 0 && dy == 0){
                continue;
            }
            if(check(x + dx, y + dy)){
                dfs(x + dx, y + dy);
            }
        }
    }
}

int main()
{
    while(~scanf("%d%d", &m, &n) && m){
        for(int i = 0; i < m; i++){
            scanf("%s", g[i]);
        }
        memset(used, 0, sizeof(used));
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(used[i][j]){
                    continue;
                }
                if(g[i][j] == '*'){
                    used[i][j] = true;
                }
                else{
                    dfs(i, j);
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
