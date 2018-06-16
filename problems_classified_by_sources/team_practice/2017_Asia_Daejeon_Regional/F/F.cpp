#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int d[4][2] = { {0, 0}, {0, 1}, {1, 1}, {1, 0} };

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m)){
        bool clockwise = true;
        int p = 0;
        int x = 1, y = 1;
        m--;
        while(n >= 2){
            int s = (n / 2) * (n / 2);
            int q = m / s;
            if(clockwise){
                x += d[(p + q) % 4][0] * (n / 2);
                y += d[(p + q) % 4][1] * (n / 2);
            }
            else{
                x += d[(p - q + 4) % 4][0] * (n / 2);
                y += d[(p - q + 4) % 4][1] * (n / 2);
            }
            if(q == 0 || q == 3){
                clockwise = !clockwise;
            }
            if(q == 3){
                p = 2 - p;
            }
            n /= 2;
            m = m % s;
        }
        printf("%d %d\n", x, y);
    }
    return 0;
}

