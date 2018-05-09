#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 105;

char g[5][maxn];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    memset(g, 0, sizeof(g));
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < n; j++){
            g[i][j] = '.';
        }
    }
    puts("YES");
    if(k % 2 == 0){
        for(int i = 1; i <= 2; i++){
            for(int j = 1; j <= k / 2; j++){
                g[i][j] = '#';
            }
        }
    }
    else{
        g[1][n / 2] = '#';
        k--;
        for(int i = n / 2 - 1, j = n / 2 + 1; i >= 1 && j < n - 1 && k > 0; i--, j++, k -= 2){
            g[1][i] = '#';
            g[1][j] = '#';
        }
        for(int i = n / 2 - 1, j = n / 2 + 1; i >= 1 && j < n - 1 && k > 0; i--, j++, k -= 2){
            g[2][i] = '#';
            g[2][j] = '#';
        }
    }
    for(int i = 0; i < 4; i++){
        puts(g[i]);
    }
    return 0;
}
