#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int INF = 0x3f3f3f3f;

int ar[maxn];
int s[maxn];
int dp[maxn][maxn];

inline int sum(int a, int b)
{
    return s[b] - s[a-1];
}

inline int dist(int a, int b)
{
    if(dp[a][b] < INF){
        return dp[a][b];
    }
    int& ans = dp[a][b];
    if(a == b){
        ans = 0;
    }
    else{
        for(int i = a; i < b; i++){
            ans = min(ans, dist(a, i) + dist(i + 1, b) + sum(a, b));
        }
    }
    return ans;
}

int main()
{
    int n;
    while(~scanf("%d", &n)){
        s[0] = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", ar + i);
            s[i] = s[i-1] + ar[i];
        }
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                dp[i][j] = INF;
            }
        }
        printf("%d\n", dist(1, n));
    }
    return 0;
}
