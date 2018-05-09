#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100005;

int p[maxn], g[maxn];
bool used[maxn];
int n, k;

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d", p + i);
    }
    for(int i = 1; i <= n; i++){
        if(!used[p[i]]){
            int c = 0, t = 0;
            for(int j = p[i]; j >= 0 && !used[j] && c < k; j--, c++){
                t = j;
            }
            if(c >= k){
                for(int j = t; j <= p[i]; j++){
                    g[j] = t;
                    used[j] = true;
                }
            }
            else{
                for(int j = t - 1; j >= 0 && used[j] && g[j] == g[t - 1]; j--){
                    c++;
                }
                if(c <= k){
                    for(int j = t; j <= p[i]; j++){
                        g[j] = g[t - 1];
                        used[j] = true;
                    }
                }
                else{
                    for(int j = t; j <= p[i]; j++){
                        g[j] = t;
                        used[j] = true;
                    }
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        printf("%d%c", g[p[i]], i == n ? '\n' : ' ');
    }
    return 0;
}
