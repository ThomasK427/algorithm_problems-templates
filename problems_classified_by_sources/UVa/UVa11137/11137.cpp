#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxk = 25;
const int maxn = 10005;

LL dp[maxn][maxn];

inline int cube(int x){
    return x * x * x;
}

int main()
{
    dp[0][0] = 1;
    for(int i = 1; i <= 21; i++){
        for(int j = 0; j <= 10000; j++){
            if(j >= cube(i)){
                dp[i][j] = dp[i - 1][j] + dp[i][j - cube(i)];
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int n;
    while(~scanf("%d", &n)){
        printf("%lld\n", dp[21][n]);
    }
    return 0;
}

