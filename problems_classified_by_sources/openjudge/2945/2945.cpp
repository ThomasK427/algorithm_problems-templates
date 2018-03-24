#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;

int ar[maxn], dp[maxn];

int main()
{
    int k;
    scanf("%d", &k);
    for(int i = 1; i <= k; i++){
        scanf("%d", ar + i);
    }
    int ans = 0;
    for(int i = 1; i <= k; i++){
        dp[i] = 1;
        for(int j = 1; j < i; j++){
            if(ar[j] >= ar[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}
