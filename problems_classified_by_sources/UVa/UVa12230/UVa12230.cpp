#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, d, kase = 0;
    while(~scanf("%d%d", &n, &d) && (n || d)){
        int p, L, v;
        double ans = d;
        for(int i = 0; i < n; i++){
            scanf("%d%d%d", &p, &L, &v);
            ans += 2.0 * L / v - L;
        }
        printf("Case %d: %.3f\n\n", ++kase, ans);
    }
    return 0;
}
