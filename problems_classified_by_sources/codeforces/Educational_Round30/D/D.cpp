#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 100005;

int ar[maxn];

void divide(int L, int R, int c){
    c--;
    int mid = L + R >> 1;
    divide(L, mid, c / 2);
    divide(mid, R, (c + 1) / 2);

}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    if((k > 2 * n - 1) && (k % 2 == 0)){
        puts("-1");
        return 0;
    }
    for(int i = 1; i <= n; i++){
        ar[i] = i;
    }
    divide()
    return 0;
}
