#include <bits/stdc++.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;

int a[12][105][105];

int main()
{
    //freopen("test.txt", "r", stdin);
    int n, q, c;
    while(~scanf("%d%d%d", &n, &q, &c)){
        memset(a, 0, sizeof(a));
        int x, y, s;
        for(int i = 0; i < n; i++){
            scanf("%d%d%d", &x, &y, &s);
            a[0][x][y] += s;            //注意有可能有重点，把=改成+=
            for(int j = 1; j <= c; j++){
                a[j][x][y] += (s + j) % (c + 1);
            }
        }
        int t, x1, y1, x2, y2;
        while(q--){
            scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
            t = t % (c + 1);
            int ans = 0;
            for(int i = x1; i <= x2; i++){
                for(int j = y1; j <= y2; j++){
                    ans += a[t][i][j];
                }
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}

