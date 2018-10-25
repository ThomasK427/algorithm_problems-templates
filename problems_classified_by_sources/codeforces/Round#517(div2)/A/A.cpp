#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

int main()
{
    int w, h, k;
    cin >> w >> h >> k;
    int ans = 0;
    for(int i = 0; i < k; i++){
        ans += 2 * w + 2 * h - 4;
         w -= 4;
         h -= 4;
    }
    cout << ans << endl;
    return 0;
}
