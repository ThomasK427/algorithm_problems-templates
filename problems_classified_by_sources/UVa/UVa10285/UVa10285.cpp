#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;

int g[maxn][maxn];
int dp[maxn][maxn];
int r, c;
char str[maxn];
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

inline bool check(int i, int j){
    return i >= 0 && i < r && j >= 0 && j < c;
}

int d(int i, int j){
    if(dp[i][j] > 0){
        return dp[i][j];
    }
    int& ans = dp[i][j];
    ans = 1;
    for(int k = 0; k < 4; k++){
        int x = i + dir[k][0], y = j + dir[k][1];
        if(check(x, y) && g[i][j] > g[x][y]){
            ans = max(ans, 1 + d(x, y));
        }
    }
    return ans;
}

int main()
{
    int N;
    scanf("%d", &N);
    while(N--){
        scanf("%s", str);
        scanf("%d%d", &r, &c);
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                scanf("%d", &g[i][j]);
            }
        }
        memset(dp, 0, sizeof(dp));
        int ans = 1;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                ans = max(ans, d(i, j));
            }
        }
        printf("%s: %d\n", str, ans);
    }
    return 0;
}
