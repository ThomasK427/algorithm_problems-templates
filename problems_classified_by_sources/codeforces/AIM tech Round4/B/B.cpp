#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 55;

int n, m;
int g[maxn][maxn];

LL qpow(int x)
{
    LL base = 2, res = 1;
    while(x > 0){
        if(x & 1){
            res *= base;
        }
        base = base * base;
        x >>= 1;
    }
    return res;
}

inline LL f(int x)
{
    if(x < 2){
        return 0;
    }
    else{
        return qpow(x) - 1 - x;
    }
}

int main()
{
    //freopen("test.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &g[i][j]);
        }
    }
    LL ans = n * m;
    for(int i = 1; i <= n; i++){
        int x = 0, y = 0;
        for(int j = 1; j <= m; j++){
            if(g[i][j] == 0){
                x++;
            }
            else{
                y++;
            }
        }
        ans += f(x) + f(y);
    }
    for(int j = 1; j <= m; j++){
        int x = 0, y = 0;
        for(int i = 1; i <= n; i++){
            if(g[i][j] == 0){
                x++;
            }
            else{
                y++;
            }
        }
        ans += f(x) + f(y);
    }
    printf("%lld\n", ans);
    return 0;
}
