#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    int T;
    cin >> T;
    while(T--){
        int a1, b1, c1, a2, b2, c2, a3, b3, c3, a4, b4, c4;
        cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
        cin >> a3 >> b3 >> c3 >> a4 >> b4 >> c4;
        LL x1 = a1 - a2, y1 = b1 - b2, z1 = c1 - c2;
        LL x2 = a1 - a3, y2 = b1 - b3, z2 = c1 - c3;
        LL x3 = a1 - a4, y3 = b1 - b4, z3 = c1 - c4;
        LL ans = x1 * y2 * z3 + y1 * z2 * x3 + z1 * x2 * y3 - z1 * y2 * x3 - y1 * x2 * z3 - x1 * z2 * y3;
        if(ans == 0){
            puts("Yes");
        }
        else{
            puts("No");
        }
    }
    return 0;
}
