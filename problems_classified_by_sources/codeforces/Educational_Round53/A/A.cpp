#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1005;

char s[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    gets(s);
    bool flag = false;
    if(n >= 2){
        for(int i = 0; i <= n - 2; i++){
            if(s[i] != s[i + 1]){
                s[i + 2] = '\0';
                puts("YES");
                puts(s + i);
                flag = true;
                break;
            }
        }
    }
    if(!flag){
        puts("NO");
    }
    return 0;
}
