#include <bits/stdc++.h>
using namespace std;
const double s = 8;
const double v = 1.504506;

int main()
{
    double S;
    cin >> S;
    double k = sqrt(S / s);
    printf("%.6lf\n", k * k * k * v);
    return 0;
}
