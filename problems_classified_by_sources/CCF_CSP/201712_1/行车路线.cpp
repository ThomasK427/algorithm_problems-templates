#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 505;

int s[maxn][maxn], p[maxn][maxn];
int d[maxn][2], f[maxn];
bool used[maxn];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    memset(s, INF, sizeof(s));
    memset(t, -1, sizeof(t));
    for(int i = 0; i < m; i++){
        int t, a, b, c;
        scanf("%d%d%d%d", &t, &a, &b, &c);
        s[a][b] = c;
        s[b][a] = c;
        p[a][b] = t;
        p[b][a] = t;
    }
    memset(d, INF, sizeof(d));
    memset(f, -1, sizeof(f));
    memset(used, 0, sizeof(used));
    d[1][0] = 0;
    for(int i = 1; i < n; i++){
        int u = 0;
        for(int j = 1; j <= n; j++){
            if(used[j] && (u == 0 || d[j] < d[u])){

            }
        }
    }
    return 0;
}
