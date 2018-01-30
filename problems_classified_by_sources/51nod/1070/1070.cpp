#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

bool judge(LL x)
{
    LL a = 1, b = 1;
    while(b <= x){
        if(b == x){
            return true;
        }
        LL c = a + b;
        a = b;
        b = c;
    }
    return false;
}

int main()
{
   int T;
   LL N;
   scanf("%d", &T);
   while(T--){
        scanf("%lld", &N);
        if(judge(N)){
            puts("B");
        }
        else{
            puts("A");
        }
   }
   return 0;
}
