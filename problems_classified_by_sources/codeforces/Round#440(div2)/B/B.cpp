#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 100005;

int ar[maxn];
int b[maxn];
int c[maxn];

int main()
{
    //freopen("test.txt", "r", stdin);
    int n, k, p = 0;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", ar + i);
        if(ar[i] > ar[p]){
            p = i;
        }
    }
    b[0] = ar[0];
    for(int i = 1; i < n; i++){
        b[i] = min(b[i - 1], ar[i]);
    }
    c[n - 1] = ar[n - 1];
    for(int i = n - 2; i >= 0; i--){
        c[i] = min(c[i + 1], ar[i]);
    }
    if(k == 1){
        int ans = INF;
        for(int i = 0; i < n; i++){
            ans = min(ans, ar[i]);
        }
        printf("%d\n", ans);
    }
    else if(k >= 3){
        printf("%d\n", ar[p]);
    }
    else{
        int ans = -INF;
        for(int i = 0; i < n - 1; i++){
            ans = max(ans, max(b[i], c[i + 1]));
        }
        printf("%d\n", ans);
    }
    return 0;
}
