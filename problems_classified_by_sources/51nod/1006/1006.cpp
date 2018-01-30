#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

char s[maxn], t[maxn];
int dp[maxn][maxn];
char str[maxn][maxn];

int main()
{
    while(~scanf("%s%s", s + 1, t + 1)){
        for(int i = 0; i < maxn; i++){
            dp[i][0] = 0;
            dp[0][i] = 0;
            str[i][0] = ' ';
            str[0][i] = ' ';
        }
        int m = strlen(s + 1), n = strlen(t + 1);
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s[i] == t[j]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    str[i][j] = s[i];
                }
                else{
                    if(dp[i-1][j] > dp[i][j-1]){
                        dp[i][j] = dp[i-1][j];
                        str[i][j] = ' ';
                    }
                    else{
                        dp[i][j] = dp[i][j-1];
                        str[i][j] = ' ';
                    }
                }
            }
        }
        string ans = "";
        int p = m, q = n;
        while(p > 0 && q > 0){
            if(str[p][q] != ' '){
                ans += str[p--][q--];
            }
            else{
                if(dp[p-1][q] > dp[p][q-1]){
                    p--;
                }
                else{
                    q--;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    return 0;
}
