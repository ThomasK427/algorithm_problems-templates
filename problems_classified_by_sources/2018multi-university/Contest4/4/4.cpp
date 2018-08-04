#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 105;

int a[maxn], b[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++){
            scanf("%d%d", a + i, b + i);
        }
        sort(b, b + n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            m /= b[i] + 1;
            if(m >= 1){
                ans = i + 1;
            }else{
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
