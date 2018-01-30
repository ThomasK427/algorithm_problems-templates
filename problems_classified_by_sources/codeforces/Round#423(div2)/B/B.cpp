#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 105;

char g[maxn][maxn];

int main()
{
    //freopen("test.txt", "r", stdin);
    int m, n;
    while(~scanf("%d%d", &m, &n)){
        for(int i = 0; i < m; i++){
            scanf("%s", g[i]);
        }
        int cnt = 0, left = INF, right = -INF, up = INF, down = -INF;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(g[i][j] == 'B'){
                    cnt++;
                    left = min(left, i);
                    right = max(right, i);
                    up = min(up, j);
                    down = max(down, j);
                }
            }
        }
        if(cnt == 0){
            puts("1");
        }
        else{
            int a = max(right - left + 1, down - up + 1);
            if(min(m, n) >= a){
                printf("%d\n", a * a - cnt);
            }
            else{
                puts("-1");
            }
        }
    }
    return 0;
}
