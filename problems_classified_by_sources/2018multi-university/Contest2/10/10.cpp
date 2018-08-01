#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100005;

int ar[maxn], br[maxn];
int n, x, y;
vector<int> g[maxn];

int bit[maxn];

int lowbit(int x){
    return x & (-x);
}

void add(int id){
    while(id <= n){
        bit[id]++;
        id += lowbit(id);
    }
}

int sum(int id){
    int res = 0;
    while(id > 0){
        res += bit[id];
        id -= lowbit(id);
    }
    return res;
}

int main()
{
    while(~scanf("%d%d%d", &n, &x, &y)){
        for(int i = 1; i <= n; i++){
            g[i].clear();
        }
        memset(bit, 0, sizeof(bit));
        for(int i = 1; i <= n; i++){
            scanf("%d", ar + i);
            br[i] = ar[i];
        }
        sort(br + 1, br + n + 1);
        int m = unique(br + 1, br + n + 1) - br - 1;
        for(int i = 1; i <= n; i++){
            int p = lower_bound(br + 1, br + m + 1, ar[i]) - br;
            g[p].push_back(i);
        }
        LL ans = 0;
        for(int i = m; i >= 1; i--){
            for(int j = 0; j < g[i].size(); j++){
                ans += sum(g[i][j]);
            }
            for(int j = 0; j < g[i].size(); j++){
                add(g[i][j]);
            }
        }
        ans *= min(x, y);
        printf("%lld\n", ans);
    }
    return 0;
}
