#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 50005;

LL ar[maxn];

int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%lld", ar + i);
        if(i > 1){
            ar[i] += ar[i - 1];
        }
    }
    int Q, i, l;
    scanf("%d", &Q);
    while(Q--){
        scanf("%d%d", &i, &l);
        printf("%lld\n", ar[i + l - 1] - ar[i - 1]);
    }
    return 0;
}
