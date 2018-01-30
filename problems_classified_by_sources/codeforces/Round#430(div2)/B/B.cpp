#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int ar[maxn];

int main()
{
    //freopen("test.txt", "r", stdin);
    int r, d, n, x, y, R, cnt = 0;
    cin >> r >> d >> n;
    for(int i = 0; i < n; i++){
        //cin >> x >> y >> R;
        scanf("%d%d%d", &x, &y, &R);
        double l = sqrt(x * x + y * y);
        if(l + R <= r && l - R >= r - d){
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
