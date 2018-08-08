#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;

int a[maxn][maxn], b[maxn][maxn], c[maxn][maxn];
int m, n, p, q;

void process(){
    if(n != p){
        puts("ERROR");
    }else{
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= q; j++){
                c[i][j] = 0;
                for(int k = 1; k <= n; k++){
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= q; j++){
                printf("%d%c", c[i][j], j == q ? '\n' : ' ');
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int kase = 1; kase <= T; kase++){
        scanf("%d%d%d%d", &m, &n, &p, &q);
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                scanf("%d", &a[i][j]);
            }
        }
        for(int i = 1; i <= p; i++){
            for(int j = 1; j <= q; j++){
                scanf("%d", &b[i][j]);
            }
        }
        printf("Case %d:\n", kase);
        process();
    }
    return 0;
}
