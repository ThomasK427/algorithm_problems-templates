#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;

int ar[30];
char str[maxn];

int main()
{
    scanf("%s", str);
    int len = strlen(str);
    memset(ar, 0, sizeof(ar));
    for(int i = 0; i < len; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] - 'A' + 'a';
        }
        ar[str[i] - 'a' + 1]++;
    }
    sort(ar + 1, ar + 27);
    int ans = 0;
    for(int i = 1; i <= 26; i++){
        ans += i * ar[i];
    }
    printf("%d\n", ans);
    return 0;
}
