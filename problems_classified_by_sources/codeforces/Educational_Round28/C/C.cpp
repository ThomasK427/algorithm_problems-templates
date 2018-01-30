#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

LL ar[maxn];
LL s[maxn];

inline LL sum(int u, int v){
    if(u == 0){
        return s[v - 1];
    }
    else{
        return s[v - 1] - s[u - 1];
    }
}

int main()
{
    //freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    LL Sum = 0;
    for(int i = 0; i < n; i++){
        scanf("%lld", ar + i);
        s[i] = Sum + ar[i];
        Sum = s[i];
    }
    int u = 0, v = 0, w = 0, ans = sum(0, 0) - sum(0, 0) + sum(0, 0) - sum(0, n);
    for(int k = 0; k < n; k++){
        LL thisSum = 0, minSum = 0;
        int a = 0, b = 0;
        for(int i = 0; i < k; i++){
            thisSum += ar[i];
            if(thisSum < minSum){
                b = i + 1;
                minSum = thisSum;
            }
            if(thisSum > 0){
                a = i + 1;
                b = i + 1;
                thisSum = 0;
            }
        }
        if(ans < sum(0, a) - sum(a, b) + sum(b, k) - sum(k, n)){
            ans = sum(0, a) - sum(a, b) + sum(b, k) - sum(k, n);
            u = a;
            v = b;
            w = k;
        }
    }
    printf("%d %d %d\n", u, v, w);
    return 0;
}
