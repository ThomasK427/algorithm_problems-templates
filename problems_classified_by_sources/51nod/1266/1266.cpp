#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

int main()
{
    int N, L, x, ans1 = 0, ans2 = 0;
    scanf("%d%d", &N, &L);
    for(int i = 0; i < N; i++){
        scanf("%d", &x);
        ans1 = max(ans1, min(x, L - x));
        ans2 = max(ans2, max(x, L - x));
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}
