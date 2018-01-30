#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);

int main()
{
    long long n;
    scanf("%lld", &n);
    n %= 6;
    printf("%.0f\n", 2.0 * cos(n * PI / 3.0));
    return 0;
}
