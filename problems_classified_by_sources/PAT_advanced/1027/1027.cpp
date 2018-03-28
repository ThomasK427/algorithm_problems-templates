#include <bits/stdc++.h>
using namespace std;

char f(int x){
    if(x < 10){
        return x + '0';
    }
    else{
        return x - 10 + 'A';
    }
}

char str[10];

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    str[0] = '#';
    str[1] = f(a / 13);
    str[2] = f(a % 13);
    str[3] = f(b / 13);
    str[4] = f(b % 13);
    str[5] = f(c / 13);
    str[6] = f(c % 13);
    str[7] = '\0';
    puts(str);
    return 0;
}
