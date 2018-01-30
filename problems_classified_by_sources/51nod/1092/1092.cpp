#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1005;

int dp[maxn][maxn];
char str[maxn];

int f(int i, int j)
{
    if(dp[i][j] >= 0){
        return dp[i][j];
    }
    int& ans = dp[i][j];
    if(i > j){
        return 0;
    }
    else if(i == j){
        return 1;
    }
    else if(str[i] == str[j]){
        ans = f(i + 1, j - 1) + 2;
    }
    else{
        ans = max(f(i, j - 1), f(i + 1, j));
    }
    return ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%s", str);
    int n = strlen(str);
    printf("%d\n", n - f(0, n - 1));
    return 0;
}

