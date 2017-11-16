#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 50005;

int sumv[maxn * 4 + 10];
int ar[maxn];

void PushUp(int node){
    sumv[node] = sumv[node * 2] + sumv[node * 2 + 1];
}

void BuildTree(int node, int bg, int ed){
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

void Set(int id, int x, int node, int L, int R){
    if(id < L || id > R){
        return;
    }
    if(L == R){
        sumv[node] = x;
        return;
    }
    int mid = (L + R) >> 1;
    Set(id, x, node * 2, L, mid);
    Set(id, x, node * 2 + 1, mid + 1, R);
    PushUp(node);
}

int QuerySum(int a, int b, int node, int L, int R){
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
    int n = 6;
    for(int i = 1; i <= n; i++){
        scanf("%d", ar + i);
    }
    BuildTree(1, 1, n);
    char ch;
    int a, b;
    while(cin >> ch >> a >> b){
        if(ch == 's'){
            Set(a, b, 1, 1, n);
        }
        else{
            cout << QuerySum(a, b, 1, 1, n) << endl;
        }
    }
    return 0;
}
