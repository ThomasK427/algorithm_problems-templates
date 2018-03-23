#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 10005;

int N, K;
double ar[maxn];

bool check(double x){
    LL sum = 0;
    for(int i = 0; i < N; i++){
        sum += LL(ar[i] / x);
    }
    return sum >= K;
}

int main()
{
    scanf("%d%d", &N, &K);
    for(int i = 0; i < N; i++){
        scanf("%lf", ar + i);
    }
    double lb = 1e-3, ub = 1e6;
    for(int i = 0; i < 200; i++){
        double mid = (lb + ub) / 2;
        if(check(mid)){
            lb = mid;
        }
        else{
            ub = mid;
        }
    }
    //不能直接输出printf("%.2f\n", lb);，这样是四舍五入，但要求截尾
    printf("%.2f\n", LL(100 * lb) / 100.0);
    return 0;
}
