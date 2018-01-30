#include <bits/stdc++.h>
using namespace std;
typedef long long L;
const int maxn = 1000000 + 5;

L ar[maxn], cr[maxn];

int main()
{
    //freopen("test.txt", "r", stdin);
    int n;
    while(~scanf("%d", &n)){
        L sum = 0;
        for(int i = 0; i < n; i++){
            scanf("%lld", ar + i);
            sum += ar[i];
        }
        L M = sum / n;
        sum = 0;
        for(int i = 0; i < n; i++){
            sum += ar[i];
            cr[i] = sum - M * (i + 1);
        }
        sort(cr, cr + n);
        L median = cr[n / 2], ans = 0;
        for(int i = 0; i < n; i++){
            if(median > cr[i]){
                ans += median - cr[i];
            }
            else{
                ans += cr[i] - median;
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}
