#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 100005;

int ar[maxn], br[maxn];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", ar + i);
    }
    for(int i = 1; i <= m; i++){
        scanf("%d", br + i);
    }
    int ans = -1;
    int i = 0, j = 0, suma = 0, sumb = 0;
    while(i <= n && j <= m){
        if(suma == sumb){
            ans++;
            suma = ar[++i];
            sumb = br[++j];
        }
        else if(suma < sumb){
            suma += ar[++i];
        }
        else{
            sumb += br[++j];
        }
    }
    printf("%d\n", ans);
    return 0;
}
