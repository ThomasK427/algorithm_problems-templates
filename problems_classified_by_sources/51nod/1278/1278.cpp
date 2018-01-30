#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;

struct Node{
    int c, r;
    friend bool operator<(const Node& e1, const Node& e2){
        return e1.c - e1.r < e2.c - e2.r;
    }
}E[maxn];

int a[maxn];
int N;

int BinSearch(int x)
{
    int low = 0, high = N;
    while(low < high){
        int mid = (low + high) >> 1;
        if(a[mid] > x){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }
    return high;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d%d", &E[i].c, &E[i].r);
    }
    sort(E, E + N);
    for(int i = 0; i < N; i++){
        a[i] = E[i].c - E[i].r;
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        ans += N - BinSearch(E[i].c + E[i].r);
    }
    printf("%d\n", ans);
    return 0;
}
