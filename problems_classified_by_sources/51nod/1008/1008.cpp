#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    LL N, P;
    while(~scanf("%lld%lld", &N, &P)){
        LL res = 1;
        for(LL i = 1; i <= N; i++){
            res = res * i % P;
        }
        printf("%lld\n", res);
    }
    return 0;
}
