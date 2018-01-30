#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const int INF = 0x3f3f3f3f;

int g[maxn][maxn];
int dist[maxn];
int score[maxn];
bool vis[maxn];
int point[maxn];
int n;

bool cmp(int a, int b)
{
    if(dist[a] != dist[b]){
        return dist[a] > dist[b];
    }
    else{
        return score[a] < score[b];
    }
}

void Dijkstra(int src)
{
    for(int i = 0; i <= n; i++){
        dist[i] = INF;
        score[i] = 0;
        vis[i] = false;
    }
    dist[src] = 0;
    score[src] = point[src];
    while(true){
        int v = -1;
        for(int i = 0; i < n; i++){
            if(!vis[i] && (v == -1 || cmp(v, i))){
                v = i;
            }
        }
        if(v == -1)break;
        vis[v] = true;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(dist[i] > dist[v] + g[v][i]){
                    dist[i] = dist[v] + g[v][i];
                    score[i] = score[v] + point[i];
                }
                else if(dist[i] == dist[v] + g[v][i] && score[i] < score[v] + point[i]){
                    score[i] = score[v] + point[i];
                }
            }
        }
    }
}

int main()
{
    int m, st, ed;
    while(~scanf("%d%d%d%d", &n, &m, &st, &ed)){
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                g[i][j] = INF;
            }
        }
        for(int i = 0; i < n; i++){
            scanf("%d", point + i);
        }
        for(int i = 0; i < m; i++){
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            g[x][y] = z;
            g[y][x] = z;
        }
        Dijkstra(st);
        printf("%d %d\n", dist[ed], score[ed]);
    }
    return 0;
}
