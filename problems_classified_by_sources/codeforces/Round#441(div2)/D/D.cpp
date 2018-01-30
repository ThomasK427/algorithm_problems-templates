#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 300005;

int p[maxn];
int bit[maxn];
int ar[maxn];
int ans[maxn];
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
        scanf("%d", p + i);
    }
    ans[0] = 1;
    int pos = n;
    for(int i = 1; i <= n; i++){
        ar[p[i]] = 1;
        while(ar[pos]){
            pos--;
        }
        add(p[i]);
        ans[i] = sum(pos) + 1;
    }
    for(int i = 0; i <= n; i++){
        printf("%d%c", ans[i], i == n ? '\n' : ' ');
    }
    return 0;
}
