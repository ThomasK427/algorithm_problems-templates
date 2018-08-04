#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        LL n;
        scanf("%lld", &n);
        if(n % 3 == 0){
            LL ans = (n / 3) * (n / 3) * (n / 3);
            printf("%lld\n", ans);
        }else if(n % 4 == 0){
            LL ans = (n / 4) * (n / 4) * (n / 2);
            printf("%lld\n", ans);
        }else{
            puts("-1");
        }
    }
    return 0;
}
