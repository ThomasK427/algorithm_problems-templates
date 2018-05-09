#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1005;

int main()
{
    int k, n, s, p;
    scanf("%d%d%d%d", &k, &n, &s, &p);
    int a = (n + s - 1) / s;
    int b = (k * a + p - 1) / p;
    printf("%d\n", b);
    return 0;
}
