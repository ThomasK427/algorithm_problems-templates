#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 1005;

struct Node{
    int h, m;
}E[maxn], F[maxn];

int diff(const Node& a, const Node& b){
    return (b.h * 60 + b.m) - (a.h * 60 + a.m);
}

Node inc(Node a, int b){
    a.h += b / 60;
    a.m += b % 60;
    if(a.m >= 60){
        a.h++;
        a.m -= 60;
    }
    return a;
}

int main()
{
    int n, s;
    scanf("%d%d", &n, &s);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &E[i].h, &E[i].m);
        F[i] = inc(E[i], 1);
    }
    bool flag = false;
    Node base;
    base.h = 0;
    base.m = 0;
    if(diff(base, E[0]) >= s + 1){
        puts("0 0");
        flag = true;
    }
    for(int i = 0; !flag && i < n - 1; i++){
        int d = diff(F[i], E[i + 1]);
        if(d >= 2 * s + 1){
            Node t = inc(F[i], s);
            printf("%d %d\n", t.h, t.m);
            flag = true;
        }
    }
    if(!flag){
        Node t = inc(F[n - 1], s);
        printf("%d %d\n", t.h, t.m);
    }
    return 0;
}
