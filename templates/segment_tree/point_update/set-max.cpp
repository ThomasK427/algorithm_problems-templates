#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 50005;

int maxv[maxn * 4 + 10];
int ar[maxn];

void PushUp(int node)
{
    maxv[node] = max(maxv[node * 2], maxv[node * 2 + 1]);
}

void BuildTree(int node, int bg, int ed)
{
    if(bg == ed){
        maxv[node] = ar[bg];
    }
    else{
        int mid = (bg + ed) >> 1;
        BuildTree(node * 2, bg, mid);
        BuildTree(node * 2 + 1, mid + 1, ed);
        PushUp(node);
    }
}

void Set(int id, int x, int node, int L, int R)
{
    if(id < L || id > R){
        return;
    }
    if(L == R){
        maxv[node] = x;
        return;
    }
    int mid = (L + R) >> 1;
    Set(id, x, node * 2, L, mid);
    Set(id, x, node * 2 + 1, mid + 1, R);
    PushUp(node);
}

int QueryMax(int a, int b, int node, int L, int R)
{
    if(a > R || b < L){
        return -INF;
    }
    if(a <= L && R <= b){
        return maxv[node];
    }
    int res = -INF, mid = (L + R) >> 1;
    res = max(res, QueryMax(a, b, node * 2, L, mid));
    res = max(res, QueryMax(a, b, node * 2 + 1, mid + 1, R));
    return res;
}

int main()
{
    int N, M;
    while(~scanf("%d%d", &N, &M)){
        for(int i = 1; i <= N; i++){
            scanf("%d", ar + i);
        }
        BuildTree(1, 1, N);
        int A, B;
        char C;
        for(int i = 0; i < M; i++){
            getchar();
            scanf("%c%d%d", &C, &A, &B);
            if(C == 'Q'){
                printf("%d\n", QueryMax(A, B, 1, 1, N));
            }
            else{
                Set(A, B, 1, 1, N);
            }
        }
    }
    return 0;
}
