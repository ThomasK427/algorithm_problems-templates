#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL Q = 1000000007;

LL inv(LL x)
{
    LL n = Q - 2, base = x, res = 1;
    while(n > 0){
        if(n & 1){
            res = res * base % Q;
        }
        n >>= 1;
        base = base * base % Q;
    }
    return res;
}

LL C(LL n, LL k)
{
    LL a = 1, b = 1;
    for(LL i = n; i >= n - k + 1; i--){
        a = a * i % Q;
    }
    for(LL i = 1; i <= k; i++){
        b = b * i % Q;
    }
    return a * inv(b) % Q;
}

int main()
{
    LL M, N;
    while(~scanf("%lld%lld", &M, &N)){
        printf("%lld\n", C(M + N - 2, M - 1));
    }
    return 0;
}

