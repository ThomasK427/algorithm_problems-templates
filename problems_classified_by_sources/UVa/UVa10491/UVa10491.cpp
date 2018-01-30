#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a, b, c;
    while(~scanf("%lf%lf%lf", &a, &b, &c)){
        double ans = (a * b + b * b - b) / (a + b) / (a + b - c - 1);
        printf("%.5f\n", ans);
    }
    return 0;
}
