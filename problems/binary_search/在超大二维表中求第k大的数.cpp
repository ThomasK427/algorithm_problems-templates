#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 50005;

LL a[maxn], b[maxn];
LL N;

LL binSearch1(LL x, LL y){
    LL low = 0, high = N;
    while(low < high){
        LL mid = (low + high + 1) / 2;
        if(a[mid] * y < x){
            low = mid;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}

LL binSearch2(LL x, LL y){
    LL low = 0, high = N;
    while(low < high){
        LL mid = (low + high + 1) / 2;
        if(a[mid] * y <= x){
            low = mid;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}


int main()
{
    LL k;
    scanf("%lld%lld", &N, &k);
    for(int i = 1; i <= N; i++){
        scanf("%lld%lld", a + i, b + i);
    }
    sort(a + 1, a + N + 1);
    sort(b + 1, b + N + 1);
    a[0] = 0;
    b[0] = 0;
    k = N * N + 1 - k;
    LL low = a[1] * b[1], high = a[N] * b[N];
    while(low <= high){
        LL mid = low + high >> 1;
        LL sum1 = 0, sum2 = 0;
        for(int i = 1; i <= N; i++){
            sum1 += binSearch1(mid, b[i]);
            sum2 += binSearch2(mid, b[i]);
        }
        if(k > sum1 && k <= sum2){
            printf("%lld\n", mid);
            break;
        }
        else if(k <= sum1){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return 0;
}
