#include <bits/stdc++.h>
using namespace std;

//多次计算莫比乌斯函数时可以打一个O(sqrt(n))范围内的素数表来加速
int Mobius(int n){
    int x = n, cnt = 0;
    for(int i = 2; i <= x && i * i <= n; i++){
        if(x % i == 0){
            x /= i;
            if(x % i == 0){
                return 0;
            }
            cnt++;
        }
    }
    if(x > 1){
        cnt++;
    }
    return (cnt & 1) ? -1 : 1;
}

int main()  //51nod1240
{
    int n;
    scanf("%d", &n);
    printf("%d\n", Mobius(n));
    return 0;
}
