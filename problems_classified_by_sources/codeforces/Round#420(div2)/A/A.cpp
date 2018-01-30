#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 55;

int g[maxn][maxn];

int main()
{
    //freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    bool flag = true;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> g[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(g[i][j] != 1){
                bool can = false;
                for(int u = 1; u <= n; u++){
                    for(int v = 1; v <= n; v++){
                        if(i != v && j != u){
                            if(g[i][u] + g[v][j] == g[i][j]){
                                can = true;
                                goto HERE;
                            }
                        }
                    }
                }
                HERE:;
                if(can == false){
                    flag = false;
                    goto THERE;
                }
            }
        }
    }
    THERE:;
    if(flag){
        puts("Yes");
    }
    else{
        puts("No");
    }
    return 0;
}
