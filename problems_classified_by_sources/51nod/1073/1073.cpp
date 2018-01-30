#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;

int main()
{
    int N, K;
    scanf("%d%d", &N, &K);
    int ans = 0;
    for(int i = 2; i <= N; i++){
        ans = (ans + K) % i;
    }
    printf("%d\n", ans + 1);
    return 0;
}
