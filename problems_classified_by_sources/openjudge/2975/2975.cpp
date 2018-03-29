#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;

char str[maxn];
char st[] = "ENDOFINPUT";

int main()
{
    while(~scanf("%s", str) && (strcmp(str, st) != 0)){
        getchar();
        gets(str);
        int n = strlen(str);
        for(int i = 0; i < n; i++){
            if(str[i] >= 'A' && str[i] <= 'Z'){
                str[i] = (str[i] - 'A' + 21) % 26 + 'A';
            }
        }
        puts(str);
        getchar();
        gets(str);
    }
    return 0;
}
