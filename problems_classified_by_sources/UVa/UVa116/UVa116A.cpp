#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxm = 15;
const int maxn = 105;

int n, m;
int g[maxm][maxn];
int dp[maxm][maxn];

int d(int i, int j){
    int& ans = dp[i][j];
    if(ans < INF){
        return ans;
    }
    if(j == n - 1){
        ans = g[i][n - 1];
    }
    else{
        int row[3];
        for(int k = - 1; k <= 1; k++){
            row[k + 1] = (i + k + m) % m;
        }
        sort(row, row + 3);
        for(int k = 0; k < 3; k++){
            ans = min(ans, g[i][j] + d(row[k], j + 1));
        }
    }
    return ans;
}

void print(int i, int j, int x){
    int row[3];
    for(int k = -1; k <= 1; k++){
        row[k + 1] = (j + k + m) % m;
    }
    sort(row, row + 3);
    for(int k = 0; k < 3; k++){
        if(d(row[k], i) == x){
            printf(" %d", row[k] + 1);
            if(i < n - 1){
                print(i + 1, row[k], x - g[row[k]][i]);
            }
            break;
        }
    }
}

int main()
{
    while(~scanf("%d%d", &m, &n)){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                scanf("%d", &g[i][j]);
            }
        }
        memset(dp, INF, sizeof(dp));
        int ans = INF;
        for(int i = 0; i < m; i++){
            ans = min(ans, d(i, 0));
        }
        for(int i = 0; i < m; i++){
            if(d(i, 0) == ans){
                printf("%d", i + 1);
                print(1, i, ans - g[i][0]);
                break;
            }
        }
        putchar('\n');
        printf("%d\n", ans);
    }
    return 0;
}
