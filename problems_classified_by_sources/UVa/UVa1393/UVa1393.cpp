#include <bits/stdc++.h>
using namespace std;
const int maxn = 305;

int gcd[maxn][maxn];

void getGcd()
{
    for(int i = 1; i < maxn; i++){
        for(int j = 1; j < maxn; j++){
            gcd[i][j] = __gcd(i, j);
        }
    }
}

int main()
{
    getGcd();
    int m, n;
    while(~scanf("%d%d", &n, &m) && n && m){
        int ans = 0;
        for(int a = 1; a < m; a++){
            for(int b = 1; b < n; b++){
                if(gcd[a][b] == 1){
                    ans += (m - a) * (n - b) - max(0, m - 2 * a) * max(0, n - 2 * b);
                }
            }
        }
        ans *= 2;
        printf("%d\n", ans);
    }
    return 0;
}
