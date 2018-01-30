#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int main()
{
    //freopen("test.txt", "r", stdin);
    LL n, k, t;
    cin >> n >> k >> t;
    if(t >= 0 && t <= k){
        cout << t << endl;
    }
    else if(t > k && t <= n){
        cout << k << endl;
    }
    else{
        cout << n + k - t << endl;
    }
    return 0;
}
