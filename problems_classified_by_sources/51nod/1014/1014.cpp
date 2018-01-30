#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    LL P, A;
    scanf("%lld%lld", &P, &A);
    bool first = true;
    bool flag = false;
    for(LL x = 0; x <= P; x++){
        if( x * x % P == A){
            if(!first){
                putchar(' ');
            }
            first = false;
            flag = true;
            printf("%lld", x);
        }
    }
    if(flag){
        putchar('\n');
    }
    else{
        puts("No Solution");
    }
    return 0;
}
