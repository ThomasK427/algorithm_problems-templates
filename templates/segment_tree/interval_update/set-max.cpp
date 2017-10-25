#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 100024;

struct SegNode{
    int val, setMark;
}maxv[maxn * 4 + 10];

int ar[maxn];

void PushUp(int node)
{
    maxv[node].val = max(maxv[node * 2].val, maxv[node * 2 + 1].val);
}

void PushDown(int node)
{
    if(maxv[node].setMark != -INF){
        maxv[node * 2].setMark = maxv[node].setMark;
        maxv[node * 2 + 1].setMark = maxv[node].setMark;
        maxv[node * 2].val = maxv[node].setMark;
        maxv[node * 2 + 1].val = maxv[node].setMark;
        maxv[node].setMark = -INF;
    }
}

void BuildTree(int node, int bg, int ed)
{
    maxv[node].setMark = -INF;
    if(bg == ed){
        maxv[node].val = ar[bg];
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
        maxv[node].setMark = x;
        maxv[node].val = x;
        return;
    }
    PushDown(node);
    int mid = (L + R) >> 1;
    Set(a, b, x, node * 2, L, mid);
    Set(a, b, x, node * 2 + 1, mid + 1, R);
    PushUp(node);
}

int QueryMax(int a, int b, int node, int L, int R)
{
    if(a > R || b < L){
        return -INF;
    }
    if(a <= L && R <= b){
        return maxv[node].val;
    }
    PushDown(node);
    int res = -INF, mid = (L + R) >> 1;
    res = max(res, QueryMax(a, b, node * 2, L, mid));
    res = max(res, QueryMax(a, b, node * 2 + 1, mid + 1, R));
    return res;
}

void Show(int n)
{
    for(int i = 1; i <= n; i++){
        cout << maxv[i].val << " ";
    }
    cout << endl;
}

int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while(T--){
        int N, Q;
        scanf("%d%d", &N, &Q);
        for(int i = 0; i <= 4 * N; i++){
            maxv[i].setMark = -INF;
            maxv[i].val = -INF;
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
            sum += QueryMax(i, i, 1, 1, N);
        }
        printf("Case %d: The total value of the hook is %d.\n", ++kase, sum);
    }
    return 0;
}
