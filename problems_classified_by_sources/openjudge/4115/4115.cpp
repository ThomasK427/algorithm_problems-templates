#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 205;
const int maxt = 15;

struct Node{
    int x, y;
    Node():x(0), y(0){}
    Node(int xx, int yy):x(xx), y(yy){}
};

char g[maxn][maxn];
int cost[maxn][maxn][maxt];
int M, N, T;

int fx[] = {0, 0, 1, -1};
int fy[] = {1, -1, 0, 0};

bool check(int u, int v){
    return u >= 0 && u < M && v >= 0 && v < N;
}

int main()
{
    scanf("%d%d%d", &M, &N, &T);
    for(int i = 0; i < M; i++){
        scanf("%s", g[i]);
    }
    memset(cost, INF, sizeof(cost));
    int sx = 0, sy = 0, tx = 0, ty = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(g[i][j] == '@'){
                sx = i;
                sy = j;
            }
            if(g[i][j] == '+'){
                tx = i;
                ty = j;
            }
        }
    }
    queue<Node> que;
    que.push(Node(sx, sy));
    for(int i = 0; i <= T; i++){
        cost[sx][sy][i] = 0;
    }
    bool solved = false;
    while(!que.empty() && !solved){
        Node node = que.front();
        que.pop();
        int u = node.x, v = node.y;
        for(int i = 0; i < 4; i++){
            int x = u + fx[i], y = v + fy[i];
            if(check(x, y)){
                if(g[x][y] == '@'){
                    continue;
                }
                else if(g[x][y] == '+'){
                    int ans = INF;
                    for(int j = 0; j <= T; j++){
                        ans = min(ans, cost[u][v][j] + 1);
                    }
                    printf("%d\n", ans);
                    solved = true;
                    break;
                }
                else if(g[x][y] == '*'){
                    bool flag = false;
                    for(int j = 0; j <= T; j++){
                        if(cost[u][v][j] == INF){
                            continue;
                        }
                        else{
                            if(cost[u][v][j] + 1 < cost[x][y][j]){
                                cost[x][y][j] = cost[u][v][j] + 1;
                                flag = true;
                            }
                        }
                    }
                    if(flag){
                        que.push(Node(x, y));
                    }
                }
                else{
                    bool flag = false;
                    for(int j = 0; j < T; j++){
                        if(cost[u][v][j] == INF){
                            continue;
                        }
                        else{
                            if(cost[u][v][j] + 1 < cost[x][y][j + 1]){
                                cost[x][y][j + 1] = cost[u][v][j] + 1;
                                flag = true;
                            }
                        }
                    }
                    if(flag){
                        que.push(Node(x, y));
                    }
                }
            }
        }
    }
    if(!solved){
        puts("-1");
    }
    return 0;
}
