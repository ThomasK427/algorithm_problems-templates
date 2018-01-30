#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

LL f(LL n, LL m, LL r, LL p, LL q){
    return (min(p, n - r + 1) - max(1LL, p - r + 1) + 1) * (min(q, m - r + 1) - max(1LL, q - r + 1) + 1);
}

int main()
{
    map<LL, LL> mp;
    LL n, m, r, k;
    cin >> n >> m >> r >> k;
    for(LL i = 1; i <= n; i++){
        for(LL j = 1; j <= m; j++){
            mp[f(n, m, r, i, j)]++;
        }
    }
    LL sum = 0;
    for(map<LL, LL>::reverse_iterator it = mp.rbegin(); it != mp.rend(); it++){
        LL x = it->first, y = it->second;
        LL c = min(y, k);
        sum += c * x;
        k -= c;
        if(k == 0){
            break;
        }
    }
    printf("%.12f\n", double(sum) / ((n - r + 1) * (m - r + 1)));
    return 0;
}
