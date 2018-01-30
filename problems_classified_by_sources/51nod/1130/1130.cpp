#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const double pi = acos(-1.0);

int main()
{
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        if(n == 1){
            puts("1");
            continue;
        }
        double ans = 0.5 * log10(2 * pi * double(n)) + double(n) * log10(double(n) / exp(1)) + 0.5;
        printf("%.0lf\n", ans);
    }
    return 0;
}
