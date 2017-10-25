#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 50005;

int ar[maxn];

struct SegNode{
    int val, addMark;
}minv[maxn * 4 + 10];

void PushUp(int node){
    minv[node].val = min(minv[node * 2].val, minv[node * 2 + 1].val);
}

void PushDown(int node)
{
    if(minv[node].addMark){
        minv[node * 2].addMark += minv[node].addMark;
        minv[node * 2 + 1].addMark += minv[node].addMark;
        minv[node * 2].val += minv[node].addMark;
        minv[node * 2 + 1].val += minv[node].addMark;
        minv[node].addMark = 0;
    }
}

void BuildTree(int node, int bg, int ed)
{
    minv[node].addMark = 0;
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

void Add(int a, int b, int x, int node, int L, int R)
{
    if(a > R || b < L){
        return;
    }
    if(a <= L && R <= b){
        minv[node].addMark += x;
        minv[node].val += x;
        return;
    }
    PushDown(node);
    int mid = (L + R) >> 1;
    Add(a, b, x, node * 2, L, mid);
    Add(a, b, x, node * 2 + 1, mid + 1, R);
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
    return 0;
}
