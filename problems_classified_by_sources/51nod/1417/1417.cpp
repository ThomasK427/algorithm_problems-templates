#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL gcd(LL a, LL b){
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        LL A, B;
        scanf("%lld%lld", &A, &B);
        LL a = A + 3 * B, b = 4 * (A + B), g = gcd(a, b);
        printf("%lld/%lld\n", a / g, b / g);
    }
    return 0;
}
