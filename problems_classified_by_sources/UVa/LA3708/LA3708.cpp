#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("test.txt", "r", stdin);
    int n, m;
    while(~scanf("%d%d", &n, &m)){
        double ans = 0.0;
        for(int i = 1; i < n; i++){
            double pos = (double) i / n * (n + m);
            ans = fabs(pos - floor(pos + 0.5)) / (n + m);
        }
        printf("%.4lf\n", ans * 10000);
    }
    return 0;
}
