#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Q = 1e9 + 7;
const int maxn = 1005;

LL c[maxn];
LL dp[maxn];

LL qpow(LL a, LL n){
    LL base = a, res = 1LL;
    while(n > 0){
        if(n & 1){
            res = res * base % Q;
        }
        base = base * base % Q;
        n >>= 1;
    }
    return res;
}

LL inv(LL x){
    return qpow(x, Q - 2);
}

int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%lld", c + i);
    }
    dp[0] = 1;
    LL sum = c[0];
    for(int i = 1; i < N; i++){
        dp[i] = dp[i - 1];
        for(LL j = 1, k = sum + 1; j < c[i]; j++, k++){
            dp[i] = dp[i] * k % Q * inv(j) % Q;
        }
        sum += c[i];
    }
    printf("%lld\n", dp[N - 1]);
    return 0;
}
