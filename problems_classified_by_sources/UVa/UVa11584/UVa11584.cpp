#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1005;

char str[maxn];
bool s[maxn][maxn];
int dp[maxn];

int main()
{
    //freopen("test.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%s", str + 1);
        int n = strlen(str + 1);
        memset(s, false, sizeof(s));
        memset(dp, INF, sizeof(dp));
        for(int i = 1; i <= n; i++){
            int p = i, q = i;
            while(p >= 1 && q <= n && str[p] == str[q]){
                s[p][q] = true;
                p--;
                q++;
            }
        }
        for(int i = 1; i < n; i++){
            int p = i, q = i + 1;
            while(p >= 1 && q <= n && str[p] == str[q]){
                s[p][q] = true;
                p--;
                q++;
            }
        }
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                if(s[j + 1][i]){
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}
