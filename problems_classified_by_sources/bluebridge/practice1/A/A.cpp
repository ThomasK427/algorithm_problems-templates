#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ans = 0;
    for(int a = 10; a < 100; a++){
        for(int b = 10; b < 100; b++){
            bool flag = (a == 2 * (b % 10 + b / 10)) && (b == 3 * (a % 10 + a / 10));
            if(flag){
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
