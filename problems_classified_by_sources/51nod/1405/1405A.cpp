#include <stdio.h>
#include <string.h>
const int maxn = 100005;

struct Node{
    int cur, nxt;
}E[maxn * 2];
int fc[maxn], lc[maxn];
long long c[maxn], up[maxn], down[maxn];
int N, cnt = 0;

long long dfs(int k, int fa){
    long long ans = 1;
    for(int i = fc[k]; i != -1; i = E[i].nxt){
        if(E[i].cur != fa){
            ans += dfs(E[i].cur, k);
        }
    }
    c[k] = ans;
    return ans;
}

long long dfsUp(int k, int fa){
    long long ans = 0;
    for(int i = fc[k]; i != -1; i = E[i].nxt){
        if(E[i].cur != fa){
            ans += dfsUp(E[i].cur, k);
        }
    }
    up[k] = ans;
    return ans + c[k];
}

void dfsDown(int k, int fa){
    for(int i = fc[k]; i != -1; i = E[i].nxt){
        int v = E[i].cur;
        if(v != fa){
            down[v] = down[k] + up[k] + N - up[v] - c[v] * 2;
            dfsDown(v, k);
        }
    }
}

inline void read(int &x) {
    x = 0;
    char c;
    do{
        c = getchar();
    } while (c < '0' || c > '9');
    do{
        x = x * 10 + c - '0';
        c = getchar();
    } while (c >= '0' && c <= '9');
}

inline void add(int a, int b){
    E[cnt].cur = b;
    E[cnt].nxt = -1;
    if(fc[a] == -1){
        fc[a] = cnt;
        lc[a] = cnt++;
    }
    else{
        E[lc[a]].nxt = cnt;
        lc[a] = cnt++;
    }
}

int main()
{
    read(N);
    memset(fc, -1, sizeof(fc));
    for(int i = 0; i < N - 1; i++){
        int a, b;
        read(a);
        read(b);
        add(a, b);
        add(b, a);
    }
    dfs(1, -1);
    dfsUp(1, -1);
    dfsDown(1, -1);
    for(int i = 1; i <= N; i++){
        printf("%lld\n", up[i] + down[i]);
    }
    return 0;
}
