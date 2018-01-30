#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int main()
{
    LL A, B, x, y, z;
    cin >> A >> B >> x >> y >> z;
    LL p = max(0LL, 2 * x + y - A), q = max(0LL, y + 3 * z - B);
    cout << p + q << endl;
    return 0;
}
