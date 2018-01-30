#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Q = 1000000007;
const int maxn = 2005;

LL C[maxn][maxn];

int main()
{
    C[0][0] = 1;
    for(int i = 1; i < maxn; i++){
        C[i][0] = 1;
        C[i][i] = 1;
        for(int j = 1; j < i; j++){
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % Q;
        }
    }
    int M, N;
    scanf("%d%d", &M, &N);
    printf("%lld\n", C[M + N - 2][M - 1]);
    return 0;
}
