#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Q = 998244353;
const int maxn = 100005;

LL qpow(LL a, LL n){
    LL base = a % Q, res = 1;
    while(n){
        if(n & 1){
            res = res * base % Q;
        }
        base = base * base % Q;
        n >>= 1;
    }
    return res;
}

LL inv(LL x){
    return qpow(x, Q - 2);
}

LL p[maxn], xp[maxn], ep[maxn][3];
int d[maxn];

struct Node{
    int value, index;
    Node(){}
    Node(int v, int i): value(v), index(i){}
};

int main()
{
    int n;
    scanf("%d", &n);
    xp[0] = 1;
    for(int i = 1; i <= n; i++){
        scanf("%lld%d", p + i, d + i);
        p[i] = p[i] * inv(100) % Q;
        xp[i] = (1 - p[i] + Q) % Q * xp[i - 1] % Q;
    }
    stack<Node> s;
    for(int i = n; i >= 1; i--){
        while(!s.empty()){
            if(d[i] >= s.top().value){
                s.pop();
            }else{
                break;
            }
        }
        if(s.empty()){
            ep[i][0] = 0;
            ep[i][1] = 1;
            ep[i][2] = ((1 - p[i] + Q) % Q * ep[i][0] % Q + p[i] * ep[i][1] % Q) % Q;
        }else{
            int j = s.top().index;
            ep[i][0] = ep[j][2];
            ep[i][1] = (ep[j][2] + 1) % Q;
            ep[i][2] = ((1 - p[i] + Q) % Q * ep[i][0] % Q + p[i] * ep[i][1] % Q) % Q;
        }
        s.push(Node(d[i], i));
    }
    LL ans = 0;
    for(int i = 1; i <= n; i++){
        ans = (ans + xp[i - 1] * p[i] % Q * ep[i][1] % Q) % Q;
    }
    printf("%lld\n", ans);
    return 0;
}
