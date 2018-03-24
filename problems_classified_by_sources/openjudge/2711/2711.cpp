#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;

int t[maxn], dp1[maxn], dp2[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", t + i);
    }
    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));
    for(int i = 1; i <= n; i++){
        dp1[i] = 1;
        for(int j = 1; j < i; j++){
            if(t[j] < t[i]){
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }
    for(int i = n; i >= 1; i--){
        dp2[i] = 1;
        for(int j = n; j > i; j--){
            if(t[j] < t[i]){
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }
    int K = 0;
    for(int i = 1; i <= n; i++){
        K = max(K, dp1[i] + dp2[i] - 1);
    }
    printf("%d\n", n - K);
    return 0;
}
