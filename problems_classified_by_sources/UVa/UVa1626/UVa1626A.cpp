#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 105;

char str[maxn];
int dp[maxn][maxn];
int s[maxn][maxn];
int n;
char pre[maxn], post[maxn];

int d(int i, int j){
    if(dp[i][j] >= 0){
        return dp[i][j];
    }
    int& ans = dp[i][j];
    if(i == j){
        ans = 1;
    }
    else{
        ans = INF;
        if((str[i] == '(' && str[j] == ')') || (str[i] == '[' && str[j] == ']')){
            ans = d(i + 1, j - 1);
            s[i][j] = -1;
        }
        for(int k = i + 1; k <= j; k++){
            int tmp = d(i, k - 1) + d(k, j);
            if(tmp < ans){
                ans = tmp;
                s[i][j] = k;
            }
        }
    }
    return ans;
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
    if(s[i][j] < 0){
        putchar(str[i]);
        print(i + 1, j - 1);
        putchar(str[j]);
        return;
    }
    print(i, s[i][j] - 1);
    print(s[i][j], j);
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
        memset(dp, -1, sizeof(dp));
        memset(s, INF, sizeof(s));
        d(0, n - 1);
        print(0, n - 1);
        putchar('\n');
        if(T){
            putchar('\n');
        }
    }
    return 0;
}

