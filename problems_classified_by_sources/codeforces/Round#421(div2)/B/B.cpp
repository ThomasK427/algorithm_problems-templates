#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 1005;

int ar[maxn];

int main()
{
    //freopen("test.txt", "r", stdin);
    double n, a;
    cin >> n >> a;
    double e = 180.0 / n;
    int N = int(n + 0.5);
    int ans = 0;
    double dist = INF;
    for(int i = 1; i <= n - 2; i++){
        if(fabs(a - i * e) < dist){
            ans = i;
            dist = fabs(a - i * e);
        }
    }
    cout << N << " " << 1 << " " << N - ans << endl;
    return 0;
}
