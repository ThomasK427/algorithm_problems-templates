#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int p[maxn];
int dp[maxn];

int d(int m){
    if(dp[m] >= 0){
        return dp[m];
    }
    int& ans = dp[m];
    ans = p[m];
    for(int i = 1; i < m; i++){
        ans = max(ans, d(i) + d(m - i));
    }
    return ans;
}

int main()
{
    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", p + i);
    }
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= n; i++){
        cout << i << "\t" << d(i) << endl;
    }
    return 0;
}
