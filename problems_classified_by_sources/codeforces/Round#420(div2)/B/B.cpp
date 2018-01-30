#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;

inline LL f(LL x, LL y)
{
    return (x + 1) * (y + 1) * (x + y) / 2;
}

int main()
{
    //freopen("test.txt", "r", stdin);
    LL m, b;
    cin >> m >> b;
    LL ans = 0;
    for(LL x = 0; x <= b * m; x += m){
        LL y = -x / m + b;
        ans = max(ans, f(x, y));
    }
    cout << ans << endl;
    return 0;
}
