#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    double n, p, eps = 1e-10;
    while(~scanf("%lf%lf", &n, &p)){
        int k = (int)(pow(p, 1 / n) + eps);
        printf("%d\n", k);
    }
    return 0;
}
