#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 100005;

char str[maxn];
int n;
unordered_map<int, int> mp;

int main()
{
    scanf("%d", &n);
    scanf("%s", str + 1);
    int sum = 0, ans = 0;
    mp[0] = 0;
    for(int i = 1; i <= n; i++){
        sum += str[i] - '0';
        int x = 2 * sum - i;
        if(mp.count(x)){
            ans = max(ans, i - mp[x]);
        }
        else{
            mp[x] = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}
