#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 100024;

struct SegNode{
    int val, setMark;
}sumv[maxn * 4 + 10];

int ar[maxn];

void PushUp(int node)
{
    sumv[node].val = sumv[node * 2].val + sumv[node * 2 + 1].val;
}

void PushDown(int node, int L, int R)
{
    if(sumv[node].setMark != 0){
        sumv[node * 2].setMark = sumv[node].setMark;
        sumv[node * 2 + 1].setMark = sumv[node].setMark;
        int mid = (L + R) >> 1;
        sumv[node * 2].val = (mid - L + 1) * sumv[node].setMark;
        sumv[node * 2 + 1].val = (R - mid) * sumv[node].setMark;
        sumv[node].setMark = 0;
    }
}

void BuildTree(int node, int bg, int ed)
{
    sumv[node].setMark = 0;
    if(bg == ed){
        sumv[node].val = ar[bg];
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
        sumv[node].setMark = x;
        sumv[node].val = (R - L + 1) * x;
        return;
    }
    PushDown(node, L, R);
    int mid = (L + R) >> 1;
    Set(a, b, x, node * 2, L, mid);
    Set(a, b, x, node * 2 + 1, mid + 1, R);
    PushUp(node);
}

int QuerySum(int a, int b, int node, int L, int R)
{
    if(a > R || b < L){
        return 0;
    }
    if(a <= L && R <= b){
        return sumv[node].val;
    }
    PushDown(node, L, R);
    int res = 0, mid = (L + R) >> 1;
    res += QuerySum(a, b, node * 2, L, mid);
    res += QuerySum(a, b, node * 2 + 1, mid + 1, R);
    return res;
}

void Show(int n)
{
    for(int i = 1; i <= n; i++){
        cout << sumv[i].val << " ";
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
        for(int i = 1; i <= 4 * N; i++){
            sumv[i].setMark = 0;
            sumv[i].val = 0;
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
        int sum = QuerySum(1, N, 1, 1, N);
        printf("Case %d: The total value of the hook is %d.\n", ++kase, sum);
    }
    return 0;
}
