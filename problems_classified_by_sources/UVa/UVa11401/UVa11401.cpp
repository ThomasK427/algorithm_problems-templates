#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const long long maxn = 1000005;

LL f[maxn];

int main()
{
    f[3] = 0;
    for(LL i = 4; i < maxn; i++){
        f[i] = f[i-1] + ((i - 1) * (i - 2) / 2 - (i - 1) / 2) / 2;
    }
    LL n;
    while((cin >> n) && (n >= 3)){
        cout << f[n] << endl;
    }
    return 0;
}
