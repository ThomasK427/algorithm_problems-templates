#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-5;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        int N;
        double a, L;
        scanf("%d%lf%lf", &N, &a, &L);
        double r = cos(PI / N) * cos(PI / N);
        int ans = 0;
        double s = a * a * N / (4.0 * tan(PI / N));
        while(s > L + eps){
            s *= r;
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
