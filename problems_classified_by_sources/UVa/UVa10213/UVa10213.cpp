#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    int S;
    scanf("%d", &S);
    while(S--){
        LL n, V, E, F, T;
        scanf("%lld", &n);
        if(n == 0){
            F = 1;
        }
        else if(n == 1){
            F = 1;
        }
        else if(n == 2){
            F = 2;
        }
        else{
            T = (n - 3) * (n - 2) * (n - 2) / 2 - (n - 3) * (n - 2) * (2 * n - 5) / 6;
            V = n + T * n / 4;
            E = n + (T + n - 3) * n / 2;
            F = 1 + E - V;
        }
        printf("%lld\n", F);
    }
    return 0;
}
