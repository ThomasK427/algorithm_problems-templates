#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1005;

int main()
{
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    int ans = max(0, a[2] - a[0] - a[1] + 1);
    cout << ans << endl;
    return 0;
}
