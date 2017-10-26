#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 10005;

int ar[maxn];
int dp[maxn];
int pos[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", ar + i);
    }
    memset(dp, INF, sizeof(dp));
    for(int i = 0; i < n; i++){
        int p = lower_bound(dp, dp + n, ar[i]) - dp;
        dp[p] = ar[i];
        pos[i] = p + 1;
    }
    int ans = lower_bound(dp, dp + n, INF) - dp;
    int cur = ans;
    vector<int> v;
    for(int i = n - 1; i >= 0; i--){
        if(pos[i] == cur){
            v.push_back(ar[i]);
            cur--;
        }
    }
    reverse(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        printf("%d%c", v[i], i + 1 == v.size() ? '\n' : ' ');
    }
    return 0;
}
