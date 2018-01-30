#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

char str[maxn];

int main()
{
    scanf("%s", str);
    int ans = 0, n = strlen(str);
    for(int i = 0; i < n; i++){
        int p = 0;
        while(str[i + p] == str[i - p]){
            p++;
            if(i - p < 0 || i + p >= n){
                break;
            }
        }
        ans = max(ans, 2 * p - 1);
    }
    for(int i = 0; i < n - 1; i++){
        int p = 0;
        while(str[i - p] == str[i + 1 + p]){
            p++;
            if(i - p < 0 || i + 1 + p >= n){
                break;
            }
        }
        ans = max(ans, 2 * p);
    }
    printf("%d\n", ans);
    return 0;
}
