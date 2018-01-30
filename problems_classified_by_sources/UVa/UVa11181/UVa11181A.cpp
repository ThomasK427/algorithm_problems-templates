#include <bits/stdc++.h>
using namespace std;
const int maxn = 25;

int n, r;
int a[maxn];
double p[maxn], t[maxn];
double sum;

int main()
{
    int kase = 0;
    while(~scanf("%d%d", &n, &r) && (n || r)){
        for(int i = 0; i < n; i++){
            scanf("%lf", p + i);
        }
        for(int i = 0; i < n - r; i++){
            a[i] = 0;
        }
        for(int i = n - r; i < n; i++){
            a[i] = 1;
        }
        for(int i = 0; i < n; i++){
            t[i] = 0.0;
        }
        sum = 0.0;
        do{
            double tmp = 1.0;
            for(int i = 0; i < n; i++){
                if(a[i]){
                    tmp *= p[i];
                }
                else{
                    tmp *= (1.0 - p[i]);
                }
            }
            sum += tmp;
            for(int i = 0; i < n; i++){
                if(a[i]){
                    t[i] += tmp;
                }
            }
        }while(next_permutation(a, a + n));
        printf("Case %d:\n", ++kase);
        for(int i = 0; i < n; i++){
            printf("%.6f\n", t[i] / sum);
        }
    }
    return 0;
}
