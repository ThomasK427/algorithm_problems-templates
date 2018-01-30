#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int ar[maxn];

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int x1 = (n - 1) * a, x2 = (n - 1) * b, x3 = a + (n - 2) * c, x4 = b + (n - 2) * c;
    if(n == 1){
        puts("0");
    }
    else if(n == 2){
        printf("%d\n", min(a, b));
    }
    else{
        printf("%d\n", min(min(x1, x2), min(x3, x4)));
    }
    return 0;
}
