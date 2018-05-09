#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 300005;

struct Node{
    int idx, a, b;
    friend bool operator<(const Node& e1, const Node& e2){
        if(e1.a != e2.a){
            return e1.a < e2.a;
        }
        else{
            return e1.b > e2.b;
        }
    }
}E[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &E[i].a, &E[i].b);
        E[i].idx = i + 1;
    }
    sort(E, E + n);
    int p = 0;
    bool flag = false;
    for(int i = 1; i < n; i++){
        if(E[p].b >= E[i].b){
            printf("%d %d\n", E[i].idx, E[p].idx);
            flag = true;
            break;
        }
        else{
            p = i;
        }
    }
    if(!flag){
        puts("-1 -1");
    }
    return 0;
}
