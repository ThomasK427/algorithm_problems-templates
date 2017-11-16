#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1005;

int minv[maxn * 4 + 10];
int ar[maxn];

void PushUp(int node)
{
    minv[node] = min(minv[node * 2], minv[node * 2 + 1]);
}

void BuildTree(int node, int bg, int ed)
{
    if(bg == ed){
        minv[node] = ar[bg];
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
    if(id > R || id < L){
        return;
    }
    if(L == R){
        minv[node] += x;
        return;
    }
    int mid = (L + R) >> 1;
    Add(id, x, node * 2, L, mid);
    Add(id, x, node * 2 + 1, mid + 1, R);
    PushUp(node);
}

int QueryMin(int a, int b, int node, int L, int R)
{
    if(a > R || b < L){
        return INF;
    }
    if(a <= L && R <= b){
        return minv[node];
    }
    int res = INF, mid = (L + R) >> 1;
    res = max(res, QueryMin(a, b, node * 2, L, mid));
    res = max(res, QueryMin(a, b, node * 2 + 1, mid + 1, R));
    return res;
}

int main()
{
    for(int i = 0; i < maxn * 4; i++){
        minv[i] = INF;
    }
    for(int i = 1; i <= 6; i++){
        ar[i] = i;
    }
    BuildTree(1, 1, 6);
    for(int i = 1; i <= 15; i++){
        cout << minv[i] << " ";
    }
    cout << endl;
    return 0;
}
