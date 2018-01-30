#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;

unordered_map<string, int> mp;
int idx, n;
vector<int> g[maxn];
int dp[maxn][2];
bool f[maxn][2];

int d(int u, int ch, int fa){
    if(ch == 0){
        dp[u][0] = 0;
        f[u][0] = true;
        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i];
            if(v != fa){
                int p = d(v, 0, u), q = d(v, 1, u);
                if(p > q){
                    dp[u][0] += p;
                    f[u][0] = f[u][0] && f[v][0];
                }
                else if(p < q){
                    dp[u][0] += q;
                    f[u][0] = f[u][0] && f[v][1];
                }
                else{
                    dp[u][0] += p;
                    f[u][0] = false;
                }
            }
        }
    }
    else{
        dp[u][1] = 1;
        f[u][1] = true;
        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i];
            if(v != fa){
                dp[u][1] += d(v, 0, u);
                f[u][1] = f[u][1] && f[v][0];
            }
        }
        return dp[u][1];
    }
}

char buf[maxn];
string scf(){
    scanf("%s", buf);
    return buf;
}

int main()
{
    while(~scanf("%d", &n) && n){
        memset(dp, 0, sizeof(dp));
        memset(f, false, sizeof(f));
        mp.clear();
        idx = 0;
        for(int i = 0; i <= n; i++){
            g[i].clear();
        }
        string str;
        str = scf();
        mp[str] = idx++;
        for(int i = 1; i <= n - 1; i++){
            int a, b;
            str = scf();
            if(!mp.count(str)){
                mp[str] = idx++;
            }
            a = mp[str];
            str = scf();
            if(!mp.count(str)){
                mp[str] = idx++;
            }
            b = mp[str];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int p = d(0, 0, -1), q = d(0, 1, -1);
        if(p > q){
            printf("%d ", p);
            if(f[0][0]){
                puts("Yes");
            }
            else{
                puts("No");
            }
        }
        else if(p < q){
            printf("%d ", q);
            if(f[0][1]){
                puts("Yes");
            }
            else{
                puts("No");
            }
        }
        else{
            printf("%d No\n", p);
        }
        for(int i = 0; i < n; i++){
            printf("%d: %d %d\n", i, dp[i][0], dp[i][1]);
        }
    }
    return 0;
}
