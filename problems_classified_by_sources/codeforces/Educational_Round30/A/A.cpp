#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 105;

int g[maxn][maxn];
int n, m, k;

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &g[i][j]);
        }
    }
    int ans = 0, ct = 0;
    for(int j = 1; j <= m; j++){
        int res = 0, cost = 0, cnt = 0;
        for(int i = 1; i <= n; i++){
            if(g[i][j] == 1){
                int sum = 0;
                for(int a = i, b = 1; a <= n && b <= k; a++, b++){
                    sum += g[a][j];
                }
                if(sum > res){
                    res = sum;
                    cost = cnt;
                }
                cnt++;
            }
        }
        ans += res;
        ct += cost;
    }
    printf("%d %d\n", ans, ct);
    return 0;
}
