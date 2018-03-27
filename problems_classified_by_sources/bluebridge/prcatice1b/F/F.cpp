#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 30;

char str[maxn][maxn] = {"*26******",
                        "***5*2**4",
                        "***1****7",
                        "*3**2*18*",
                        "***3*9***",
                        "*54*1**7*",
                        "5****1***",
                        "6**9*7***",
                        "******75*"};
int g[maxn][maxn];
int x[maxn * maxn], y[maxn * maxn];
int n = 0;

bool check(int x, int y){
    for(int i = 0; i < 9; i++){
        if(i == x){
            continue;
        }
        else{
            if(g[i][y] == g[x][y]){
                return false;
            }
        }
    }
    for(int j = 0; j < 9; j++){
        if(j == y){
            continue;
        }
        else{
            if(g[x][j] == g[x][y]){
                return false;
            }
        }
    }
    int sx = x - x % 3, sy = y - y % 3;
    for(int i = sx; i < sx + 3; i++){
        for(int j = sy; j < sy + 3; j++){
            if(i == x && j == y){
                continue;
            }
            else{
                if(g[i][j] == g[x][y]){
                    return false;
                }
            }
        }
    }
    return true;
}

void dfs(int k){
    if(k == n){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                printf("%d%c", g[i][j], j == 8 ? '\n' : ' ');
            }
        }
        exit(0);
    }
    for(int i = 1; i <= 9; i++){
        g[x[k]][y[k]] = i;
        if(check(x[k], y[k])){
            dfs(k + 1);
        }
        g[x[k]][y[k]] = 0;
    }
}

int main()
{
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(str[i][j] == '*'){
                g[i][j] = 0;
                x[n] = i;
                y[n++] = j;
            }
            else{
                g[i][j] = str[i][j] - '0';
            }
        }
    }
    dfs(0);
    return 0;
}
