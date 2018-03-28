#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

double ar[maxn];

int main()
{
    for(int i = 0; i < 2; i++){
        int k;
        scanf("%d", &k);
        for(int j = 0; j < k; j++){
            int n;
            double a;
            scanf("%d%lf", &n, &a);
            ar[n] += a;
        }
    }
    int k = 0;
    for(int i = 1000; i >= 0; i--){
        if(abs(ar[i]) > 1e-6){
            k++;
        }
    }
    printf("%d", k);
    for(int i = 1000; i >= 0; i--){
        if(abs(ar[i]) > 1e-6){
            printf(" %d %.1f", i, ar[i]);
        }
    }
    putchar('\n');
    return 0;
}
