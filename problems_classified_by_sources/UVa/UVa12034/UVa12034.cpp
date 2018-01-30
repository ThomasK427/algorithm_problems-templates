#include <bits/stdc++.h>
using namespace std;
const int maxn = 1007;
const int Q = 10056;

int C[maxn][maxn];
int f[maxn];

void CreateTable()
{
    C[0][0] = 1;
    for(int i = 1; i < maxn; i++){
        C[i][0] = 1;
        C[i][i] = 1;
        for(int j = 1; j < i; j++){
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % Q;
        }
    }
    f[0] = 1;
    f[1] = 1;
    for(int i = 2; i < maxn; i++){
        for(int j = 1; j <= i; j++){
            f[i] = ((C[i][j] * f[i-j]) % Q + f[i]) % Q;
        }
    }
}

int main()
{
    CreateTable();
    int T, kase = 0;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        printf("Case %d: %d\n", ++kase, f[n]);
    }
    return 0;
}
