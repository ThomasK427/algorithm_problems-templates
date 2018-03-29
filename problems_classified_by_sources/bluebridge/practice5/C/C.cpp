#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 30;

LL ar[maxn] = {9, 8, 9, 9, 5, 7, 4, 2, 2, 4, 5, 6, 7, 8, 9, 3, 3, 4, 5, 1};
LL dp[maxn][maxn];

LL d(int i, int j){
    LL& ans = dp[i][j];
    if(ans >= 0){
        return ans;
    }
    if(i > j){
        ans = 1;
    }
    else if(i == j){
        ans = ar[i];
    }
    else{
        ans = 0;
        for(int k = i; k <= j; k++){
            ans = max(ans, ar[k] + d(i, k - 1) * d(k + 1, j));
        }
    }
    return ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    printf("%lld\n", d(0, 19));
    return 0;
}
