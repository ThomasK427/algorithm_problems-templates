#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;

char str[maxn];
int dp[maxn][maxn];
int n;

inline bool match(char a, char b){
    return (a == '(' && b == ')') || (a == '[' && b == ']');
}

void print(int i, int j){
    if(i > j){
        return;
    }
    if(i == j){
        if(str[i] == '(' || str[i] == ')'){
            printf("()");
        }
        else{
            printf("[]");
        }
        return;
    }
    int ans = dp[i][j];
    if(match(str[i], str[j]) && ans == dp[i + 1][j - 1]){
        printf("%c", str[i]);
        print(i + 1, j - 1);
        printf("%c", str[j]);
        return;
    }
    for(int k = i; k < j; k++){
        if(ans == dp[i][k] + dp[k + 1][j]){
            print(i, k);
            print(k + 1, j);
            return;
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    getchar();
    while(T--){
        gets(str);
        gets(str);
        n = strlen(str);
        for(int i = 0; i < n; i++){
            dp[i + 1][i] = 0;
            dp[i][i] = 1;
        }
        for(int i = n - 2; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                dp[i][j] = n;
                if(match(str[i], str[j])){
                    dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
                }
                for(int k = i; k < j; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }
        print(0, n - 1);
        putchar('\n');
        if(T){
            putchar('\n');
        }
    }
    return 0;
}
