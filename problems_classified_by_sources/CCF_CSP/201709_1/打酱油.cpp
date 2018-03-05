#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    N /= 10;
    int ans = N + N / 5 * 2 + (N % 5) / 3;
    printf("%d\n", ans);
    return 0;
}
