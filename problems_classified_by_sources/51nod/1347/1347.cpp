#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;

char str[maxn];

int main()
{
    scanf("%s", str);
    int len = strlen(str);
    if(len & 1){
        puts("NO");
    }
    else{
        for(int i = 0; i < len / 2; i++){
            if(str[i] != str[len / 2 + i]){
                puts("NO");
                return 0;
            }
        }
        puts("YES");
        return 0;
    }
    return 0;
}
