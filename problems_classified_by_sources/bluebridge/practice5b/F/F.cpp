#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 25;

struct Node{
    int x, y;
    Node(){}
    Node(int xx, int yy):x(xx), y(yy){}
};

int g[maxn][maxn];
int cost[maxn][maxn];
int dist[maxn][maxn];

int d[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int ar[maxn][2] = { {0, 0}, {0, 7}, {1, 6}, {2, 4}, {3, 1}, {3, 8}, {4, 4},
    {6, 8}, {7, 6}, {8, 1}, {9, 6} };
int br[maxn][2] = { {1, 3}, {2, 1}, {2, 7}, {3, 5}, {4, 1}, {4, 6},
    {5, 2}, {5, 7}, {6, 5}, {7, 1}, {7, 3}, {8, 6}, {8, 7}, {9, 2}, {9, 5} };
int ag[maxn];

int na = 11, nb = 15;

bool check(int x, int y){
    return x >= 0 && x < 10 && y >= 0 && y < 10 && g[x][y] != 2 && cost[x][y] == -1;
}

int main()
{
    memset(g, 0, sizeof(g));
    for(int i = 0; i < na; i++){
        int x = ar[i][0], y = ar[i][1];
        g[x][y] = 1;
    }
    for(int i = 0; i < nb; i++){
        int x = br[i][0], y = br[i][1];
        g[x][y] = 2;
    }
    for(int i = 0; i < na; i++){
        memset(cost, -1, sizeof(cost));
        queue<Node> que;
        int sx = ar[i][0], sy = ar[i][1];
        que.push(Node(sx, sy));
        cost[sx][sy] = 0;
        while(!que.empty()){
            Node nd = que.front();
            que.pop();
            int x = nd.x, y = nd.y;
            for(int i = 0; i < 4; i++){
                int u = x + d[i][0], v = y + d[i][1];
                if(check(u, v)){
                    cost[u][v] = cost[x][y] + 1;
                    que.push(Node(u, v));
                }
            }
        }
        for(int j = 0; j < na; j++){
            int tx = ar[j][0], ty = ar[j][1];
            dist[i][j] = cost[tx][ty];
        }
    }
    for(int i = 0; i < na; i++){
        ag[i] = i;
    }
    int res = INF;
    do{
        int sum = 0;
        for(int i = 0; i < na; i++){
            sum += dist[ag[i]][ag[(i + 1) % na]];
        }
        res = min(res, sum);
    }while(next_permutation(ag + 1, ag + na));
    printf("%d\n", res);
    return 0;
}
