#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 105;

int p[maxn], l[maxn], x[maxn];
int d[maxn][maxn][2];
bool used[maxn];
int M, N;

int dfs(int k, int lb, int ub){
    if(abs(lb - l[k]) > M || abs(ub - l[k]) > M){
        return INF;
    }
    used[k] = true;
    int res = p[k];
    for(int i = 1; i <= x[k]; i++){
        if(!used[d[k][i][0]]){
            res = min(res, dfs(d[k][i][0], min(lb, l[k]), max(ub, l[k])) + d[k][i][1]);
        }
    }
    used[k] = false;
    return res;
}

int main()
{
    scanf("%d%d", &M, &N);
    for(int i = 1; i <= N; i++){
        scanf("%d%d%d", p + i, l + i, x + i);
        for(int j = 1; j <= x[i]; j++){
            scanf("%d%d", &d[i][j][0], &d[i][j][1]);
        }
    }
    int ans = dfs(1, l[1], l[1]);
    printf("%d\n", ans);
    return 0;
}
