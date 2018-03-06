#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 105;

int ar[maxn];

int main()
{
    int n, d;
    scanf("%d%d", &n, &d);
    for(int i = 0; i < n; i++){
        scanf("%d", ar + i);
    }
    sort(ar, ar + n);
    int ans = 0;
    int p = 0, q = 0;
    while(q < n){
        while(ar[q] - ar[p] <= d){
            ans = max(ans, q - p + 1);
            if(q < n - 1){
                q++;
            }
            else{
                break;
            }
        }
        if(q < n - 1){
            p++;
        }
        else{
            break;
        }
    }
    printf("%d\n", n - ans);
    return 0;
}
