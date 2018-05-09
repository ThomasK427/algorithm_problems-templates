#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1005;

int main()
{
    int n, A, B, C, T;
    while(~scanf("%d%d%d%d%d", &n, &A, &B, &C, &T)){
        int sum = 0, q = (C > B ? T: 1);
        for(int i = 1; i <= n; i++){
            int t;
            scanf("%d", &t);
            int p = T - t + 1;
            int m = min(p, q);
            int ans = A + B + (C - B) * m - C;
            sum += ans;
        }
        printf("%d\n", sum);
    }
    return 0;
}
