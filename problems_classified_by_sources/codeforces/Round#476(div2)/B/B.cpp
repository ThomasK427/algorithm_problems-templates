#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 105;

char g[maxn][maxn];
int n, k;

int f(int u, int v, int k){
    if(u + v - 1 < k){
        return 0;
    }
    u = min(u, k);
    v = min(v, k);
    return u + v - k;
}

int h(int i, int j, int k){
    if(k == 1){
        return 1;
    }
    int u = 1, v = 1, tmp = 0;
    for(int o = j + 1; o < n && g[i][o] == '.'; o++){
        u++;
    }
    for(int o = j - 1; o >= 0 && g[i][o] == '.'; o--){
        v++;
    }
    tmp += f(u, v, k);
    u = 1;
    v = 1;
    for(int k = i + 1; k < n && g[k][j] == '.'; k++){
        u++;
    }
    for(int k = i - 1; k >= 0 && g[k][j] == '.'; k--){
        v++;
    }
    tmp += f(u, v, k);
    return tmp;
}

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%s", g[i]);
    }
    int x = 1, y = 1, ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(g[i][j] == '#'){
                continue;
            }
            int tmp = h(i, j, k);
            if(tmp > ans){
                x = i + 1;
                y = j + 1;
                ans = tmp;
            }
        }
    }
    printf("%d %d\n", x, y);
    return 0;
}
