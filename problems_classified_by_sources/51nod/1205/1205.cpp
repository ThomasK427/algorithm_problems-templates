#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;

struct Node{
    int a, b;
}E[maxn], F[maxn];

inline bool cmp1(const Node& e1, const Node& e2){
    return e1.a < e2.a;
}

inline bool cmp2(const Node& e1, const Node& e2){
    return e1.b > e2.b;
}

int main()
{
    int N, n = 0, m = 0, a, b;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d%d", &a, &b);
        if(a < b){
            E[n].a = a;
            E[n++].b = b;
        }
        else{
            F[m].a = a;
            F[m++].b = b;
        }
    }
    sort(E, E + n, cmp1);
    sort(F, F + m, cmp2);
    int cur1 = 0, cur2 = 0;
    for(int i = 0; i < n; i++){
        cur1 += E[i].a;
        cur2 = max(cur1, cur2) + E[i].b;
    }
    for(int i = 0; i < m; i++){
        cur1 += F[i].a;
        cur2 = max(cur1, cur2) + F[i].b;
    }
    printf("%d\n", cur2);
    return 0;
}
