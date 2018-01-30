#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, a = 0, b = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        if(x == 5){
            a++;
        }
        else{
            b++;
        }
    }
    if(b == 0){
        puts("-1");
    }
    else{
        a = a / 9 * 9;
        for(int i = 0; i < a; i++){
            putchar('5');
        }
        if(a == 0){
            putchar('0');
        }
        else{
            for(int i = 0; i < b; i++){
                putchar('0');
            }
        }
        putchar('\n');
    }
    return 0;
}
