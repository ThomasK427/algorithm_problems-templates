#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

double c[maxn];

int main()
{
    int n;
    double a, b;
    scanf("%d%lf%lf", &n, &a, &b);
    double s = 0;
    for(int i = 0; i < n; i++){
        scanf("%lf", c + i);
        s += 2 * (n - i) * c[i];
    }
    double ans = (b + n * a - s) / (n + 1);
    printf("%.2f\n", ans);
    return 0;
}
