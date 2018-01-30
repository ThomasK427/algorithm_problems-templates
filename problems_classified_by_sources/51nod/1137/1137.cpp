#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 105;

LL m1[maxn][maxn];
LL m2[maxn][maxn];

int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            scanf("%lld", &m1[i][j]);
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            scanf("%lld", &m2[i][j]);
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            LL x = 0;
            for(int k = 1; k <= N; k++){
                x += m1[i][k] * m2[k][j];
            }
            printf("%lld%c", x, j == N ? '\n' : ' ');
        }
    }
    return 0;
}
