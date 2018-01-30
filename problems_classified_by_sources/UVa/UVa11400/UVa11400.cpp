#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1005;

struct Node{
    int V, K, C, L;
    friend bool operator<(const Node& a, const Node& b){
        return a.V < b.V;
    }
}E[maxn];

int dp[maxn];
int s[maxn];

int main()
{
    int n;
    while(~scanf("%d", &n) && n){
        for(int i = 1; i <= n; i++){
            scanf("%d%d%d%d", &E[i].V, &E[i].K, &E[i].C, &E[i].L);
        }
        sort(E + 1, E + n + 1);
        s[0] = 0;
        for(int i = 1; i <= n; i++){
            s[i] = s[i - 1] + E[i].L;
        }
        memset(dp, INF, sizeof(dp));
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                dp[i] = min(dp[i], dp[j] + (s[i] - s[j]) * E[i].C + E[i].K);
            }
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}
