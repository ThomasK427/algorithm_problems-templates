#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 105;

struct Node{
    LL v, a, b;
    friend bool operator<(const Node& e1, const Node& e2){
        if(e1.a != e2.a){
            return e1.a > e2.a;
        }
        else{
            return e1.b < e2.b;
        }
    }
}E[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        LL v, a = 0, b = 0;
        scanf("%lld", &v);
        E[i].v = v;
        while(v % 3 == 0){
            a++;
            v /= 3;
        }
        while(v % 2 == 0){
            b++;
            v /= 2;
        }
        E[i].a = a;
        E[i].b = b;
    }
    sort(E, E + n);
    for(int i = 0; i < n; i++){
        printf("%lld%c", E[i].v, i == n - 1 ? '\n' : ' ');
    }
    return 0;
}
