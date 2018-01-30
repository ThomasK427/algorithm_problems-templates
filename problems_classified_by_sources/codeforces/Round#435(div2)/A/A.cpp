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
    int n, x;
    memset(ar, 0, sizeof(ar));
    scanf("%d%d", &n, &x);
    for(int i = 0; i < n; i++){
        int y;
        scanf("%d", &y);
        if(y >= 0){
            ar[y] = 1;
        }
    }
    int ans = 0;
    for(int i = 0; i < x; i++){
        if(ar[i] == 0){
            ans++;
        }
    }
    if(ar[x] == 1){
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
