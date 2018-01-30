#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 2000005;

int ar[maxn];

struct Node{
    int val, idx, other;
}E[maxn];

bool cmp1(const Node& n1, const Node& n2){
    return n1.val < n2.val;
}

bool cmp2(const Node& n1, const Node& n2){
    return n1.idx < n2.idx;
}

int main()
{
    //freopen("test.txt", "r", stdin);
    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d", ar + i);
    }
    for(int i = 0; i < m; i++){
        scanf("%d", &E[i].val);
        E[i].idx = i;
    }
    sort(ar, ar + m);
    reverse(ar, ar + m);
    sort(E, E + m, cmp1);
    for(int i = 0; i < m; i++){
        E[i].other = ar[i];
    }
    sort(E, E + m, cmp2);
    for(int i = 0; i < m; i++){
        printf("%d%c", E[i].other, i == m - 1 ? '\n' : ' ');
    }
    return 0;
}
