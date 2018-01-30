#include <bits/stdc++.h>
using namespace std;
const int maxn = 42;

int ar[4][maxn];
int dp[maxn][maxn][maxn][maxn];
int top[4];
int n;

inline int bitcount(int x){
    int cnt = 0;
    while(x){
        cnt += x % 2;
        x /= 2;
    }
    return cnt;
}

int d(int S){
    int& ans = dp[top[0]][top[1]][top[2]][top[3]];
    if(ans >= 0){
        return ans;
    }
    ans = 0;
    if(bitcount(S) >= 5){
        return ans;
    }
    for(int i = 0; i < 4; i++){
        if(top[i] < n){
            int x = ar[i][top[i]++];
            int res = 0;
            if(S & (1 << x)){
                res = 1 + d(S ^ (1 << x));
            }
            else{
                res = d(S ^ (1 << x));
            }
            ans = max(ans, res);
            top[i]--;
        }
    }
    return ans;
}

int main()
{
    while(~scanf("%d", &n) && n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 4; j++){
                scanf("%d", &ar[j][i]);
            }
        }
        memset(dp, -1, sizeof(dp));
        memset(top, 0, sizeof(top));
        printf("%d\n", d(0));
    }
    return 0;
}
