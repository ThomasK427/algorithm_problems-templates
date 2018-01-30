#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    LL n;
    int kase = 0;
    while(~scanf("%lld", &n) && n){
        if(n == 1){
            printf("Case %d: 2\n", ++kase);
        }
        else{
            LL sum = 0, k;
            LL m = LL(sqrt(n + 0.5));
            bool prime = true;
            for(LL i = 2; i <= m; i++){
                if(n % i == 0){
                    prime = false;
                    break;
                }
            }
            if(prime){
                sum = n + 1;
                //cout << "Prime: " << sum << endl;
                goto HERE;
            }
            k = 0;
            for(LL i = 2; i <= n; i++){
                if(n % i == 0){
                    LL x = 1;
                    while(n % i == 0){
                        x *= i;
                        n /= i;
                    }
                    k++;
                    sum += x;
                    //cout << x << endl;
                }
                if(n == 1)break;
            }
            if(k == 1)sum++;
            HERE:;
            printf("Case %d: %lld\n", ++kase, sum);
        }
    }
    return 0;
}
