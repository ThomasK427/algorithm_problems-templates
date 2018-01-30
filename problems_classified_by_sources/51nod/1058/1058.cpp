#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;

int grand(double x)
{
    int res = floor(x);
    if(fabs(x - res) > eps)res++;
    return res;
}

int main()
{
    int N;
    while(~scanf("%d", &N)){
        if(N == 1){
            puts("1");
            continue;
        }
        double s = 0;
        for(int i = 1; i <= N; i++){
            s += log10(i);
        }
        printf("%d\n", grand(s));
    }
    return 0;
}
