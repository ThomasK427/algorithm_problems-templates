#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL cubt(LL x)
{
    LL y = pow(x, 0.33333333333);
    for(LL i = max(0LL, y - 1); i <= y + 1; i++){
        if(i * i * i == x){
            return i;
        }
    }
    return -1LL;
}

int main()
{
    int n;
    scanf("%d", &n);
    while(n--){
        LL a, b;
        scanf("%lld%lld", &a, &b);  //ÓÃcin»á³¬Ê±
        if(a * b == 0){
            puts("No");
        }
        else{
            LL x = cubt(a * b);
            if((x > 0) && (a % x == 0) && (b % x == 0)){
                puts("Yes");
            }
            else{
                puts("No");
            }
        }
    }
    return 0;
}
