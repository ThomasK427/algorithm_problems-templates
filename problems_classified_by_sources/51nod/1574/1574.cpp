#include <stdio.h>
#include <cmath>
using namespace std;
const int maxn = 200005;

int p[maxn], s[maxn], mp[maxn];
bool vis[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", p + i);
        mp[p[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        scanf("%d", s + i);
        s[i] = mp[s[i]];
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            int x = i;
            do{
                vis[x] = true;
                ans += abs(s[x] - x);
                x = s[x];
            }while(x != i);
        }
    }
    ans /= 2;
    printf("%lld\n", ans);
    return 0;
}
