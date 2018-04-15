#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 20;

char s[maxn][maxn];
int g[maxn][maxn];
int N, M, S;

bool check(int x, int y){
    return x >= 1 && x <= N && y >= 1 && y <= M;
}

int main()
{
    while(~scanf("%d%d%d", &N, &M, &S) && (N || M || S)){
        for(int i = 1; i <= N; i++){
            scanf("%s", s[i] + 1);
        }
        int x = 1, y = S, idx = 0;
        memset(g, 0, sizeof(g));
        bool flag = false;
        while(check(x, y)){
            if(g[x][y] == 0){
                g[x][y] = ++idx;
            }
            else{
                printf("%d step(s) before a loop of %d step(s)\n", g[x][y] - 1, ++idx - g[x][y]);
                flag = true;
                break;
            }
            if(s[x][y] == 'N'){
                x--;
            }
            else if(s[x][y] == 'E'){
                y++;
            }
            else if(s[x][y] == 'S'){
                x++;
            }
            else{
                y--;
            }
        }
        if(!flag){
            printf("%d step(s) to exit\n", idx);
        }
    }
    return 0;
}
