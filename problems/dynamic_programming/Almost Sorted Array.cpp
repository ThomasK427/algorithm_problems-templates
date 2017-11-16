/**
*Almost Sorted Array icpc2015长春 HDU5532
*求序列的最长非降子序列的长度和最长不上升子序列的长度
*取两者中的最大值，若大于等于n-1，则满足条件
*/

#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 100005;

int ar[maxn], dp[maxn];
int n;

int lnds(){
    memset(dp, INF, sizeof(dp));
    int len = 1;
    dp[len] = ar[1];
    for(int i = 2; i <= n; i++){
        if(ar[i] >= dp[len]){
            dp[++len] = ar[i];
        }
        else{
            *upper_bound(dp + 1, dp + n + 1, ar[i]) = ar[i];
        }
    }
    return len;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", ar + i);
        }
        int len = lnds();
        reverse(ar + 1, ar + n + 1);
        len = max(len, lnds());
        if(len >= n - 1){
            puts("YES");
        }
        else{
            puts("NO");
        }
    }
    return 0;
}
