#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 1005;

int ar[maxn];

int main()
{
    //freopen("test.txt", "r", stdin);
    int c, v0, v1, a, l;
    cin >> c >> v0 >> v1 >> a >> l;
    int ans = 0, sp = v0, spp = v0;
    while(c > 0){
        c -= sp;
        ans++;
        spp = min(v1, spp + a);
        sp = spp - l;
    }
    cout << ans << endl;
    return 0;
}
