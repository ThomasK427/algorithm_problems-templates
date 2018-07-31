#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        int l, r;
        scanf("%d%d", &l, &r);
    }
    for(int i = 0; i < n; i++){
        printf("%d", i % 2);
    }
    putchar('\n');
    return 0;
}
