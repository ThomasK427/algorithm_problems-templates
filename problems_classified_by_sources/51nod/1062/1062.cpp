#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 100005;

int a[maxn], m[maxn];

int main()
{
    a[0] = 0;
    a[1] = 1;
    m[1] = 1;
    for(int i = 2; i <= 100000; i++){
        if(i & 1){
            a[i] = a[i / 2] + a[i / 2 + 1];
        }
        else{
            a[i] = a[i / 2];
        }
        m[i] = max(m[i - 1], a[i]);
    }
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        printf("%d\n", m[n]);
    }
    return 0;
}

