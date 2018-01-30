#include <bits/stdc++.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const int maxn = 100005;

int n;
vector<int> g[maxn];
double ans = 0.0;

void dfs(int id, int fa, int k, double p)
{
    int s = 0;
    if(fa <= 0){
        s = g[id].size();
    }
    else{
        s = g[id].size() - 1;
    }
    if(s == 0){
        ans += k * p;
        return;
    }
    else{
        for(int i = 0; i < g[id].size(); i++){
            if(g[id][i] != fa){
                dfs(g[id][i], id, k + 1, p / s);
            }
        }
    }
}

int main()
{
    //freopen("test.txt", "r", stdin);
        scanf("%d", &n);
        int a, b;
        for(int i = 0; i < n - 1; i++){
            scanf("%d%d", &a, &b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(1, -1, 0, 1.0);
        printf("%.8lf\n", ans);

    return 0;
}
