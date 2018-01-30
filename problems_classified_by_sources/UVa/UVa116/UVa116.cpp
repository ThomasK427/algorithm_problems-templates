#include <bits/stdc++.h>
using namespace std;

int g[15][105];
int d[15][105];
int next[15][105];
int m, n;

int main()
{
    //freopen("test.txt", "r", stdin);
    while(~scanf("%d%d", &m, &n)){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                scanf("%d", &g[i][j]);
            }
        }
        int ans = INT_MAX, first = 0;
        for(int j = n - 1; j >= 0; j--){
            for(int i = 0; i < m; i++){
                if(j == n - 1){
                    d[i][j] = g[i][j];
                }
                else{
                    int rows[3] = {i, (i - 1 + m) % m, (i + 1 + m) % m};
                    sort(rows, rows + 3);
                    d[i][j] = INT_MAX;
                    for(int k = 0; k < 3; k++){
                        int v = d[rows[k]][j+1] + g[i][j];
                        if(v < d[i][j]){
                            d[i][j] = v;
                            next[i][j] = rows[k];
                        }
                    }
                }
                if(j == 0 && d[i][j] < ans){
                    ans = d[i][j];
                    first = i;
                }
            }
        }
        printf("%d", first + 1);
        for(int i = next[first][0], j = 1; j < n; i = next[i][j], j++){
            printf(" %d", i + 1);
        }
        printf("\n%d\n", ans);
    }

    return 0;
}
