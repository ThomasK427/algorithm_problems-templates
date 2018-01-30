#include <bits/stdc++.h>
using namespace std;
const int maxn = 310;
const int Q = 1000000000;
typedef long long LL;

char str[maxn];
int d[maxn][maxn];

int dp(int i, int j){
    if(i == j){
        return 1;
    }
    if(str[i] != str[j]){
        return 0;
    }
    int& ans = d[i][j];
    if(ans >= 0){
        return ans;
    }
    ans = 0;
    for(int k = i + 2; k <= j; k++){
        if(str[i] == str[k]){
            ans = (ans + (LL)dp(i + 1, k - 1) * (LL)dp(k, j)) % Q;
        }
    }
    return ans;
}

int main()
{
    while(~scanf("%s", str)){
        memset(d, -1, sizeof(d));
        printf("%d\n", dp(0, strlen(str) - 1));
    }
    return 0;
}
