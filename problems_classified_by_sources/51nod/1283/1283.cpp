#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL Sqrt(LL x)
{
    LL ans = LL(sqrt(x)) + 1;
    while(x % ans != 0)ans--;
    return ans;
}

int main()
{
    LL S;
    cin >> S;
    LL x = Sqrt(S), y = S / x;
    cout << 2 * (x + y) << endl;
    return 0;
}
