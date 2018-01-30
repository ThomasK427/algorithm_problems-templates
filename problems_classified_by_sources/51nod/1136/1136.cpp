#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    int m = int(sqrt(N + 0.5)), x = N, ans = N;
    for(int i = 2; i <= x && i <= m; i++){
        if(x % i == 0){
            ans = ans / i * (i - 1);
            while(x % i == 0){
                x /= i;
            }
        }
    }
    if(x > 1){
        ans = ans / x * (x - 1);
    }
    printf("%d\n", ans);
    return 0;
}
