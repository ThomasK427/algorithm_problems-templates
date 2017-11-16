#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 50005;

int sumv[maxn * 4 + 10];
int ar[maxn];

void PushUp(int node)
{
    sumv[node] = sumv[node * 2] + sumv[node * 2 + 1];
}

void BuildTree(int node, int bg, int ed)
{
    if(bg == ed){
        sumv[node] = ar[bg];
    }
    else{
        int mid = (bg + ed) >> 1;
        BuildTree(node * 2, bg, mid);
        BuildTree(node * 2 + 1, mid + 1, ed);
        PushUp(node);
    }
}

void Add(int id, int x, int node, int L, int R)
{
    if(id < L || id > R){
        return;
    }
    if(L == R){
        sumv[node] += x;
        return;
    }
    int mid = (L + R) >> 1;
    Add(id, x, node * 2, L, mid);
    Add(id, x, node * 2 + 1, mid + 1, R);
    PushUp(node);
}

int QuerySum(int a, int b, int node, int L, int R)
{
    if(a > R || b < L){
        return 0;
    }
    if(a <= L && R <= b){
        return sumv[node];
    }
    int res = 0, mid = (L + R) >> 1;
    res += QuerySum(a, b, node * 2, L, mid);
    res += QuerySum(a, b, node * 2 + 1, mid + 1, R);
    return res;
}

int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while(T--){
        printf("Case %d:\n", ++kase);
        int N;
        scanf("%d", &N);
        for(int i = 0; i < N; i++){
            scanf("%d", ar + i);
        }
        BuildTree(1, 0, N - 1);
        string cmd;
        while((cin >> cmd) && (cmd != "End")){
            if(cmd == "Query"){
                int a, b;
                scanf("%d%d", &a, &b);
                printf("%d\n", QuerySum(a, b, 1, 1, N));
            }
            else if(cmd == "Add"){
                int id, x;
                scanf("%d%d", &id, &x);
                Add(id, x, 1, 1, N);
            }
            else{
                int id, x;
                scanf("%d%d", &id, &x);
                Add(id, -x, 1, 1, N);
            }
        }
    }
    return 0;
}
