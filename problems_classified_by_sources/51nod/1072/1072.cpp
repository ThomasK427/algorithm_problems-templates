#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const long double C = 1.61803398874989484820458;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        LL x, y;
        scanf("%lld%lld", &x, &y);
        if(x > y){
            swap(x, y);
        }
        LL z = y - x;
        long double w = C * z;
        if((w >= x) && (w - x < 1.0)){
            puts("B");
        }
        else{
            puts("A");
        }
    }
    return 0;
}
