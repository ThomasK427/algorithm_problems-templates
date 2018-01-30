#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;

char str[maxn];

int main()
{
    while(~scanf("%s", str)){
        int n = strlen(str), a = 0, b = 0;
        for(int i = 0; i < n; i++){
            if(str[i] == '0'){
                b++;
                if(str[(i + 1) % n] == '0'){
                    a++;
                }
            }
        }
        if(a * n > b * b){
            puts("SHOOT");
        }
        else if(a * n < b * b){
            puts("ROTATE");
        }
        else{
            puts("EQUAL");
        }
    }
    return 0;
}
