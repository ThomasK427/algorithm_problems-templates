#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Q = 1e9 + 7;
const int maxn = 100005;

int ar[maxn];
LL dp[maxn];
LL mp[maxn];

int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", ar + i);
    }
    memset(mp, 0, sizeof(mp));
    dp[0] = 0;
    for(int i = 1; i <= N; i++){
        if(mp[ar[i]] == 0){
            dp[i] = (dp[i - 1] * 2 + 1) % Q;
        }
        else{
            dp[i] = (dp[i - 1] * 2 + Q - dp[mp[ar[i]] - 1]) % Q;
        }
        mp[ar[i]] = i;
    }
    printf("%lld\n", dp[N]);
    return 0;
}
