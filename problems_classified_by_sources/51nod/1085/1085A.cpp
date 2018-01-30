#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int maxk = 10005;

int w[maxn], p[maxn];
int dp[maxk];

int main()
{
    int N, W;
    while(~scanf("%d%d", &N, &W)){
        for(int i = 1; i <= N; i++){
            scanf("%d%d", w + i, p + i);
        }
        for(int j = 0; j <= W; j++){
            dp[j] = 0;
        }
        for(int i = 1; i <= N; i++){
            for(int j = W; j >= w[i]; j--){
                dp[j] = max(dp[j], dp[j-w[i]] + p[i]);
            }
        }
        printf("%d\n", dp[W]);
    }
    return 0;
}
