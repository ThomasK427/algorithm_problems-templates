#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Q = 1000000007;

int main()
{
    int n;
    cin >> n;
    LL ans = n + 1;
    for(int i = 0; i < n - 2; i++){
        ans = ans * 2 % Q;
    }
    cout << ans << endl;
    return 0;
}
