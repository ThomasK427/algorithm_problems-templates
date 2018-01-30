#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 130;
const int maxs = 2060;

int st[maxn];
int dp[maxs][maxs];
char str[maxn];
int m, n;

int d(int s1, int s2){
    int& ans = dp[s1][s2];
    if(ans >= 0){
        return ans;
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if((s1 & st[i]) == s2){
            cnt++;
        }
    }
    if(cnt <= 1){
        ans = 0;
        return ans;
    }
    ans = INF;
    for(int i = 0; i < m; i++){
        if(s1 & (1 << i)){
            continue;
        }
        ans = min(ans, max(d(s1 | (1 << i), s2), d(s1 | (1 << i), s2 | (1 << i))) + 1);
    }
    return ans;
}

int main()
{
    //freopen("test.txt", "r", stdin);
    while(~scanf("%d%d", &m, &n) && (m || n)){
        memset(st, 0, sizeof(st));
        for(int i = 0; i < n; i++){
            scanf("%s", str);
            for(int j = 0; j < m; j++){
                if(str[j] == '1'){
                    st[i] |= (1 << j);
                }
            }
        }
        memset(dp, -1, sizeof(dp));
        printf("%d\n", d(0, 0));
    }
    return 0;
}
