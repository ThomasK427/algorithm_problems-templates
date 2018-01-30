#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;

int s[maxn];
int maxv[maxn * 4];
int N;

void BuildTree(int node, int bg, int ed)
{
    if(bg == ed){
        maxv[node] = s[bg];
        return;
    }
    int mid = (bg + ed) >> 1;
    BuildTree(node * 2, bg, mid);
    BuildTree(node * 2 + 1, mid + 1, ed);
    maxv[node] = max(maxv[node * 2], maxv[node * 2 + 1]);
}

int Query(int a, int b, int node, int L, int R)
{
    if(a > R || b < L){
        return 0;
    }
    if(a <= L && R <= b){
        return maxv[node];
    }
    int mid = (L + R) >> 1;
    int res = 0;
    res = max(res, Query(a, b, node * 2, L, mid));
    res = max(res, Query(a, b, node * 2 + 1, mid + 1, R));
    return res;
}

int main()
{
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", s + i);
    }
    BuildTree(1, 1, N);
    int Q, a, b;
    scanf("%d", &Q);
    while(Q--){
        scanf("%d%d", &a, &b);
        printf("%d\n", Query(a + 1, b + 1, 1, 1, N));
    }
    return 0;
}
