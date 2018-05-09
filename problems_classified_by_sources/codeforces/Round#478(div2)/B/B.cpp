#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 1005;

LL ar[maxn], br[maxn];

int main()
{
    for(int i = 0; i < 14; i++){
        scanf("%lld", ar + i);
    }
    LL ans = 0;
    for(int i = 0; i < 14; i++){
        for(int j = 0; j < 14; j++){
            br[j] = ar[j];
        }
        LL s = br[i];
        br[i] = 0;
        for(int j = 0; j < 14; j++){
            br[j] += s / 14;
        }
        s %= 14;
        for(int j = i + 1; s > 0; j++, s--){
            br[j % 14]++;
        }
        LL res = 0;
        for(int j = 0; j < 14; j++){
            if(br[j] % 2 == 0){
                res += br[j];
            }
        }
        ans = max(ans, res);
    }
    printf("%lld\n", ans);
    return 0;
}
