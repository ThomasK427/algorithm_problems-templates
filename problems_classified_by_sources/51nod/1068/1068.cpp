#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

char s[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%s", s);
        int len = strlen(s);
        int res = 0;
        for(int i = 0; i < len; i++){
            res = (res * 10 + (s[i] - '0')) % 3;
        }
        if(res){
            puts("A");
        }
        else{
            puts("B");
        }
    }
    return 0;
}
