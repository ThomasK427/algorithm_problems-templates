#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL fd(LL m){
    for(LL i = 0; ; i++){
        if(i * (i - 1) / 2 >= m){
            return i;
        }
    }
}

int main()
{
    LL n, m;
    scanf("%lld%lld", &n, &m);
    LL a = max(0LL, n - 2 * m);
    LL b = n - fd(m);
    printf("%lld %lld\n", a, b);
    return 0;
}
