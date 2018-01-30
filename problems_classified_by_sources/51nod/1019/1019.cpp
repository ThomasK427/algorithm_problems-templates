#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;

struct Node{
    int val, idx;
    friend bool operator<(const Node& n1, const Node& n2){
        return n1.val < n2.val;
    }
}E[maxn];

int bit[maxn];
int n;

inline int lowbit(int x){
    return x & (-x);
}

int sum(int x){
    int ret = 0;
    while(x > 0){
        ret += bit[x];
        x -= lowbit(x);
    }
    return ret;
}

void add(int x){
    while(x <= n){
        bit[x]++;
        x += lowbit(x);
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &E[i].val);
        E[i].idx = i;
    }
    sort(E + 1, E + n + 1);
    long long ans = 0;
    for(int i = n; i >= 1; i--){
        ans += (n - E[i].idx) - (sum(n) - sum(E[i].idx));
        add(E[i].idx);
    }
    printf("%lld\n", ans);
    return 0;
}
