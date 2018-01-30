#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;

struct Node{
    int a, b;
    friend bool operator<(const Node& e1, const Node& e2){
        return min(e1.a, e2.b) < min(e2.a, e1.b);
    }
}E[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &E[i].a, &E[i].b);
    }
    sort(E, E + n);
    int cur1 = 0, cur2 = 0;
    for(int i = 0; i < n; i++){
        cur1 += E[i].a;
        cur2 = max(cur1, cur2) + E[i].b;
    }
    printf("%d\n", cur2);
    return 0;
}
