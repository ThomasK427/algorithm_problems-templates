#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Q = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int maxn = 1005;

LL c[maxn][maxn];

int main()
{
    for(int i = 1; i <= 1000; i++){
        c[i][0] = 1;
        c[i][i] = 1;
        for(int j = 1; j < i; j++){
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % Q;
        }
    }
    LL ans = 0;
    for(int i = 0; i <= 500; i++){
        ans = (ans + c[1000][i]) % Q;
    }
    cout << ans << endl;
    return 0;
}
