#include <stdio.h>
using namespace std;
const int maxn = 1005;

char str[maxn];
int dp[maxn][maxn];
int n;

int main()
{
    scanf("%d", &n);
    scanf("%s", str);
    dp[n][n] = 0;
    for(int i = n - 1; i >= 0; i--){
        for(int j = i; j >= 0; j--){
            if(str[i] == str[j]){
                dp[i][j] = dp[i + 1][j + 1] + 1;
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    int q;
    scanf("%d", &q);
    while(q--){
        int a, b;
        scanf("%d%d", &a, &b);
        if(b > a){
            int t = a;
            a = b;
            b = t;
        }
        printf("%d\n", dp[a][b]);
    }
    return 0;
}
