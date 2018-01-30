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
    LL l, r, x, y, k;
    cin >> l >> r >> x >> y >> k;
    bool flag = false;
    for(LL b = x; b <= y; b++){
        LL a = b * k;
        if(a >= l && a <= r){
            flag = true;
            break;
        }
        if(a > r){
            break;
        }
    }
    if(flag){
        puts("YES");
    }
    else{
        puts("NO");
    }
    return 0;
}
