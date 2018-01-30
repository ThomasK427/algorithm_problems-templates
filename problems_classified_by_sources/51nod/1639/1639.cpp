#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

double dp[maxn];

int main()
{
    dp[1] = 1.0;
    for(int i = 2; i <= 1000; i++){
        dp[i] = dp[i - 1] * (2 * i - 2) / (2 * i - 1);
    }
    int n;
    scanf("%d", &n);
    printf("%.6f\n", dp[n]);
    return 0;
}
