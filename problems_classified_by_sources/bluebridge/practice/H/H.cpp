#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;

int g[maxn][maxn];
int sum(int x, int y){
    if(x < 0 || y < 0){
        return 0;
    }
    else{
        return g[x][y];
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    memset(g, 0, sizeof(g));
    for(int i = 0; i < n; i++){
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        g[x][y] += w;
    }
    for(int i = 0; i <= 2000; i++){
        for(int j = 1; j <= 2000; j++){
            g[i][j] += g[i][j - 1];
        }
    }
    for(int j = 0; j <= 2000; j++){
        for(int i = 1; i <= 2000; i++){
            g[i][j] += g[i - 1][j];
        }
    }
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%d\n", sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1));
    }
    return 0;
}
