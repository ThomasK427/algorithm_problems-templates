#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 100024;

struct SegNode{
    int val, setMark;
}minv[maxn * 4 + 10];

int ar[maxn];

void PushUp(int node)
{
    minv[node].val = min(minv[node].val, minv[node].val);
}

void PushDown(int node)
{
    if(minv[node].setMark != INF){
        minv[node * 2].setMark = minv[node].setMark;
        minv[node * 2 + 1].setMark = minv[node].setMark;
        minv[node * 2].val = minv[node].setMark;
        minv[node * 2 + 1].val = minv[node].setMark;
        minv[node].setMark = INF;
    }
}

void BuildTree(int node, int bg, int ed)
{
    minv[node].setMark = INF;
    if(bg == ed){
        minv[node].val = ar[bg];
    }
    else{
        int mid = (bg + ed) >> 1;
        BuildTree(node * 2, bg, mid);
        BuildTree(node * 2 + 1, mid + 1, ed);
        PushUp(node);
    }
}

void Set(int a, int b, int x, int node, int L, int R)
{
    if(a > R || b < L){
        return;
    }
    if(a <= L && R <= b){
        minv[node].setMark = x;
        minv[node].val = x;
        return;
    }
    PushDown(node);
    int mid = (L + R) >> 1;
    Set(a, b, x, node * 2, L, mid);
    Set(a, b, x, node * 2 + 1, mid + 1, R);
    PushUp(node);
}

int QueryMin(int a, int b, int node, int L, int R)
{
    if(a > R || b < L){
        return INF;
    }
    if(a <= L && R <= b){
        return minv[node].val;
    }
    PushDown(node);
    int res = INF, mid = (L + R) >> 1;
    res = min(res, QueryMin(a, b, node * 2, L, mid));
    res = min(res, QueryMin(a, b, node * 2 + 1, mid + 1, R));
    return res;
}

int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while(T--){
        int N, Q;
        scanf("%d%d", &N, &Q);
        for(int i = 0; i <= 4 * N; i++){
            minv[i].setMark = INF;
            minv[i].val = INF;
        }
        for(int i = 1; i <= N; i++){
            ar[i] = 1;
        }
        BuildTree(1, 1, N);
        int X, Y, Z;
        while(Q--){
            scanf("%d%d%d", &X, &Y, &Z);
            Set(X, Y, Z, 1, 1, N);
        }
        int sum = 0;
        for(int i = 1; i <= N; i++){
            sum += QueryMin(i, i, 1, 1, N);
        }
        printf("Case %d: The total value of the hook is %d.\n", ++kase, sum);
    }
    return 0;
}

