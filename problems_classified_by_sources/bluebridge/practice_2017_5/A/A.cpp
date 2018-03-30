#include <bits/stdc++.h>
using namespace std;

int main()
{
    for(int i = 1; i <= 9; i++){
        for(int j = 0; j <= 9; j++){
            int x = (i + j) * 11, y = abs(i * 10 + j - j * 10 - i);
            if(x - y == 32){
                printf("%d\n", y);
            }
        }
    }
    return 0;
}
