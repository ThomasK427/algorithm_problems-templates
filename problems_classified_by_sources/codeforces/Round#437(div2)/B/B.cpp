#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int p[maxn];
int dp[maxn];

int main()
{
    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", p + i);
    }
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            dp[i] = max(dp[i], p[j] + dp[i - j]);
        }
    }
    for(int i = 1; i <= n; i++){
        cout << i << "\t" << dp[i] << endl;
    }
    return 0;
}
