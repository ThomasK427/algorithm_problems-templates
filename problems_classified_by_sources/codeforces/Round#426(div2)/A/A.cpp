#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

char str[4] = { '^', '>', 'v', '<' };

int main()
{
    char c1, c2;
    int r;
    while(cin >> c1 >> c2 >> r){
        r %= 4;
        int p0 = find(str, str + 4, c1) - str, p1, p2;
        p1 = (p0 + r) % 4;
        p2 = (p0 - r + 4) % 4;
        if(str[p1] == c2 && str[p2] != c2){
            printf("cw\n");
        }
        else if(str[p1] != c2 && str[p2] == c2){
            printf("ccw\n");
        }
        else{
            printf("undefined\n");
        }
    }
    return 0;
}
