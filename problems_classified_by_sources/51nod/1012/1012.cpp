#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    int A, B;
    while(~scanf("%d%d", &A, &B)){
        printf("%lld\n", LL(A) * LL(B) / LL(__gcd(A, B)));
    }
    return 0;
}
