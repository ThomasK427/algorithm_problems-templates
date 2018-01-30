#include <stdio.h>
typedef long long LL;
const LL INT_MAX = (1LL << 31);
using namespace std;

LL extgcd(LL a, LL b, LL& x, LL& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    else{
        LL d = extgcd(b, a % b, y, x);
        y -= x * (a / b);
        return d;
    }
}

int main()
{
    //freopen("test.txt", "r", stdin);
    //freopen("wa.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--){
        LL N, A, B;
        scanf("%lld%lld%lld", &N, &A, &B);
        LL x, y, d = extgcd(A, B, x, y);
        if((N + 1) % d != 0){
            puts("0");
        }
        else{
            x = x * (N + 1) / d;
            LL dx = B / d;
            if(x - dx >= 1){
                if(x % dx == 0){
                    x = dx;
                }
                else{
                    x %= dx;
                }
            }
            else if(x <= 0){
                x = x % dx + dx;
            }
            LL cnt = 0;
            if(A * x <= N){
                cnt = (N - A * x) / (A * dx) + 1LL;
            }
            printf("%lld\n", cnt);
        }
    }
    return 0;
}
