#include <stdio.h>
typedef long long LL;

LL gcd(LL a, LL b){
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int T;
    scanf("%d", &T);
    LL a, b, x, y;
    while(T--){
        scanf("%lld%lld%lld%lld", &a, &b, &x, &y);
        if(gcd(a, b) == gcd(x, y)){
            puts("Yes");
        }
        else{
            puts("No");
        }
    }
    return 0;
}
