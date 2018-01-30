#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;

char str[maxn];

int main()
{
    while(~scanf("%s", str)){
        int len = strlen(str);
        sort(str, str + len);
        do{
            printf("%s\n", str);
        }while(next_permutation(str, str + len));
    }
    return 0;
}
