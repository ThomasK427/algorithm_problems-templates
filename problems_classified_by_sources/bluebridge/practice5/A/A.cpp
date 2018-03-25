#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;

int g[maxn][maxn];

int main()
{
    int n = 101, c = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            g[i][j] = c++;
        }
    }
    int t = (n + 1) / 2, a = t - 1, ave = g[t][t];
    int ans = n * n - 2 * a * (a + 1);
    ans *= ave;
    printf("%d\n", ans);
    return 0;
}
