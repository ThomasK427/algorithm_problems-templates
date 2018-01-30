#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;

char str[maxn];
int len[maxn];

int main()
{
    scanf("%s", str);
    int n = strlen(str);
    len[0] = 1;
    for(int i = 1, j = 0; j < n * 2 - 1; i++){
        int p = i / 2, q = i - p, r = (j + 1) / 2 + len[j] - 1;
        len[i] = r < q ? 0 : min(r - q + 1, len[j * 2 - i]);
        while(p > len[i] - 1 && q + len[i] < n && str[p - len[i]] == str[q + len[i]]){
            len[i]++;
        }
        if(q + len[i] - 1 > r){
            j = i;
        }
    }
    int ans = 0;

    printf("%d\n", ans);
    return 0;
}
