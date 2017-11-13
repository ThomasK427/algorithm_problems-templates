#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 100005;

int a[maxn], b[maxn];
int n, s, t;

void maintain(int x){
    int lb = (x / s) * s, rb = min(n, lb + s) - 1;
    if(x == rb){
        b[x] = a[x];
        x--;
    }
    while(x >= lb){
        b[x] = max(b[x + 1], a[x]);
        x--;
    }
}

void modify(int x, int y){
    a[x] = y;
    maintain(x);
}

int query(int x, int y){
    int x_pos = x / s, y_pos = y / s;
    int res = -INF;
    if(x_pos == y_pos){
        for(int i = x; i <= y; i++){
            res = max(res, a[i]);
        }
    }
    else{
        res = b[x];
        for(int i = x_pos + 1; i < y_pos; i++){
            res = max(res, b[i * s]);
        }
        for(int i = y_pos * s; i <= y; i++){
            res = max(res, a[i]);
        }
    }
    return res;
}

void init(){
    for(int i = 1; i <= t; i++){
        maintain(min(n, i * s) - 1);
    }
}

int main()
{
    int m;
    scanf("%d%d", &n, &m);
    s = int(sqrt(n));
    t = (n + s - 1) / s;
    for(int i = 0; i < n; i++){
        scanf("%d", a + i);
    }
    init();
    for(int i = 0; i < m; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", query(x, y));
    }
    return 0;
}
