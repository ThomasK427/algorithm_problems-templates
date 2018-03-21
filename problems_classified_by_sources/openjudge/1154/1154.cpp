#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;

int r, s;
char g[maxn][maxn];
bool used[maxn];
int ans = 0;
int fx[] = {0, 0, 1, -1};
int fy[] = {1, -1, 0, 0};

bool check(int x, int y){
    return x >= 0 && x < r && y >= 0 && y < s && !used[g[x][y] - 'A'];
}

void dfs(int x, int y, int k){
    ans = max(ans, k);
    used[g[x][y] - 'A'] = true;
    for(int i = 0; i < 4; i++){
        int u = x + fx[i], v = y + fy[i];
        if(check(u, v)){
            dfs(u, v, k + 1);
        }
    }
    used[g[x][y] - 'A'] = false;
}

int main()
{
    scanf("%d%d", &r, &s);
    memset(used, 0, sizeof(used));
    for(int i = 0; i < r; i++){
        scanf("%s", g[i]);
    }
    dfs(0, 0, 1);
    printf("%d\n", ans);
    return 0;
}
