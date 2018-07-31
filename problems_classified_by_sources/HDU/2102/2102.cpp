#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 20;

char g[2][maxn][maxn];
int vis[2][maxn][maxn];
int N, M, T;
const int fx[] = {0, 0, 1, -1}, fy[] = {1, -1, 0, 0};

struct Node{
    int z, x, y;
    Node(){}
    Node(int zz, int xx, int yy):z(zz), x(xx), y(yy){}
};

bool check(int z, int x, int y){
    return x >= 0 && x < N && y >= 0 && y < M && vis[z][x][y] == INF && g[z][x][y] != '*';
}

int main()
{
    //freopen("test.txt", "r", stdin);
    int C;
    scanf("%d", &C);
    while(C--){
        scanf("%d%d%d", &N, &M, &T);
        for(int k = 0; k < 2; k++){
            for(int i = 0; i < N; i++){
                scanf("%s", g[k][i]);
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(g[0][i][j] == '#' && g[1][i][j] == '#'){
                    g[0][i][j] = '*';
                    g[1][i][j] = '*';
                }
                if(g[0][i][j] == '#' && g[1][i][j] == '*'){
                    g[0][i][j] = '*';
                }
                if(g[0][i][j] == '*' && g[1][i][j] == '#'){
                    g[1][i][j] = '*';
                }
            }
        }
        int pz = 0, px = 0, py = 0;
        for(int k = 0; k < 2; k++){
            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    if(g[k][i][j] == 'P'){
                        pz = k;
                        px = i;
                        py = j;
                    }
                }
            }
        }
        memset(vis, INF, sizeof(vis));
        vis[0][0][0] = 0;
        queue<Node> que;
        que.push(Node(0, 0, 0));
        while(!que.empty()){
            Node cur = que.front();
            que.pop();
            for(int i = 0; i < 4; i++){
                int z = cur.z, x = cur.x + fx[i], y = cur.y + fy[i];
                if(check(z, x, y)){
                    vis[z][x][y] = vis[cur.z][cur.x][cur.y] + 1;
                    que.push(Node(z, x, y));
                    if(g[z][x][y] == '#' && vis[1 - z][x][y] == INF){
                        vis[1 - z][x][y] = vis[z][x][y];
                        que.push(Node(1 - z, x, y));
                    }
                }
            }
        }
        if(vis[pz][px][py] <= T){
            puts("YES");
        }
        else{
            puts("NO");
        }
    }
    return 0;
}
