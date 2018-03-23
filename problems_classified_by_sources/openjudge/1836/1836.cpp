#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

double ar[maxn];
int dp1[maxn], dp2[maxn];
bool used[maxn];

//注意1 2 3 3 3 2 1这种情况

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lf", ar + i);
    }
    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));
    dp1[1] = 1;
    for(int i = 2; i <= n; i++){
        dp1[i] = 1;
        for(int j = 1; j < i; j++){
            if(ar[j] < ar[i]){
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }
    dp2[n] = 1;
    for(int i = n - 1; i >= 1; i--){
        dp2[i] = 1;
        for(int j = n; j >= 1; j--){
            if(ar[j] < ar[i]){
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }
    memset(used, 0, sizeof(used));
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            int t = n;
            for(int j = n; j >= 1; j--){
                if(ar[i] == ar[j]){
                    t = j;
                    break;
                }
            }
            used[i] = true;
            used[t] = true;
            ans = max(ans, dp1[i] + dp2[t] + (i == t ? -1: 0));
        }
    }
    printf("%d\n", n - ans);
    return 0;
}
