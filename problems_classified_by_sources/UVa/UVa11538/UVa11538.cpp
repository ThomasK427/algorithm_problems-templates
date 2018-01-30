#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n, m, ans;

int main()
{
    while((cin >> n >> m) && n && m){
        if(n > m){
            swap(n, m);
        }
        ans = m * n * (m + n - 2) + 2 * n * (n - 1) * (3 * m - n - 1) / 3;
        cout << ans << endl;
    }
    return 0;
}
