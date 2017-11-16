#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 50005;

int ar[maxn];

struct SegNode{
    int val, addMark;
}sumv[maxn * 4 + 10];

void PushUp(int node){
    sumv[node].val = sumv[node * 2].val + sumv[node * 2 + 1].val;
}

void PushDown(int node, int L, int R)
{
    if(sumv[node].addMark){
        sumv[node * 2].addMark += sumv[node].addMark;
        sumv[node * 2 + 1].addMark += sumv[node].addMark;
        int mid = (L + R) >> 1;
        sumv[node * 2].val += (mid - L + 1) * sumv[node].addMark;
        sumv[node * 2 + 1].val += (R - mid) * sumv[node].addMark;
        sumv[node].addMark = 0;
    }
}

void BuildTree(int node, int bg, int ed)
{
    sumv[node].addMark = 0;
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

void Add(int a, int b, int x, int node, int L, int R)
{
    if(a > R || b < L){
        return;
    }
    if(a <= L && R <= b){
        sumv[node].addMark += x;
        sumv[node].val += (R - L + 1) * x;
        return;
    }
    PushDown(node, L, R);
    int mid = (L + R) >> 1;
    Add(a, b, x, node * 2, L, mid);
    Add(a, b, x, node * 2 + 1, mid + 1, R);
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

int main()
{
    return 0;
}
