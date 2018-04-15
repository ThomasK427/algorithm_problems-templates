#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 505;
const int maxm = 2505;

vector<P> g[maxn];
bool inQue[maxn];
int incount[maxn], d[maxn];
int N, M, W;

bool spfa(){
    memset(inQue, 0, sizeof(inQue));
    memset(incount, 0, sizeof(incount));
    memset(d, INF, sizeof(d));
    queue<int> que;
    que.push(1);
    d[1] = 0;
    inQue[1] = true;
    incount[1] = 1;
    while(!que.empty()){
        int u = que.front();
        que.pop();
        for(int i = 0; i < g[u].size(); i++){
            P v = g[u][i];
            if(d[v.first] > d[u] + v.second){
                d[v.first] = d[u] + v.second;
                if(!inQue[v.first]){
                    que.push(v.first);
                    inQue[v.first] = true;
                    incount[v.first]++;
                    if(incount[v.first] >= N){
                        return true;
                    }
                }
            }
        }
        inQue[u] = false;
    }
    return false;
}

int main()
{
    int F;
    scanf("%d", &F);
    while(F--){
        scanf("%d%d%d", &N, &M, &W);
        for(int i = 0; i <= N; i++){
            g[i].clear();
        }
        for(int i = 0; i < M; i++){
            int S, E, T;
            scanf("%d%d%d", &S, &E, &T);
            g[S].push_back(P(E, T));
            g[E].push_back(P(S, T));
        }
        for(int i = 0; i < W; i++){
            int S, E, T;
            scanf("%d%d%d", &S, &E, &T);
            g[S].push_back(P(E, -T));
        }
        bool flag = spfa();
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
