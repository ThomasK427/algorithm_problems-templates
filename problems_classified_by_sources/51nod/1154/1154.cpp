#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 5005;

bool s[maxn][maxn];
int dp[maxn];
char str[maxn];

inline bool check(int i, int j){
    while(i < j){
        if(str[i] != str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main()
{
    scanf("%s", str + 1);
    int n = strlen(str + 1);
    for(int i = 1; i <= n; i++){
        dp[i] = INF;
        for(int j = 0; j < i; j++){
            if(check(j + 1, i)){
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
