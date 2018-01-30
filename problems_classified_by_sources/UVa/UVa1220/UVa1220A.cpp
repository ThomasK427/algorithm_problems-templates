#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;

int dp[maxn][2];
bool f[maxn][2];
int par[maxn];
int degree[maxn];

map<string, int> mp;
int idx, n;

char buf[maxn];
string scf(){
    scanf("%s", buf);
    return buf;
}

int main()
{
    while(~scanf("%d", &n) && n){
        memset(degree, 0, sizeof(degree));
        memset(par, -1, sizeof(par));
        for(int i = 0; i < n; i++){
            dp[i][0] = 0;
            dp[i][1] = 1;
            f[i][0] = true;
            f[i][1] = true;
        }
        mp.clear();
        idx = 0;
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
            par[a] = b;
            degree[b]++;
        }
        queue<int> que;
        for(int i = 0; i < n; i++){
            if(degree[i] == 0){
                que.push(i);
            }
        }
        while(!que.empty()){
            int u = que.front();
            que.pop();
            int fa = par[u];
            dp[fa][1] += dp[u][0];
            f[fa][1] = f[fa][1] && f[u][0];
            int p = dp[u][0], q = dp[u][1];
            if(p > q){
                dp[fa][0] += p;
                f[fa][0] = f[fa][0] && f[u][0];
            }
            else if(p < q){
                dp[fa][0] += q;
                f[fa][0] = f[fa][0] && f[u][1];
            }
            else{
                dp[fa][0] += p;
                f[fa][0] = false;
            }
            degree[fa]--;
            if(degree[fa] == 0 && fa != 0){
                que.push(fa);
            }
        }
        int p = dp[0][0], q = dp[0][1];
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
            if(f[1][0]){
                puts("Yes");
            }
            else{
                puts("No");
            }
        }
        else{
            printf("%d No\n", p);
        }
    }
    return 0;
}

