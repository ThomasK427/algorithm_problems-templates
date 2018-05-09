#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;

char s[maxn];
int mp[maxn * maxn];

int main()
{
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    for(int i = 0; i < n - 1; i++){
        int a = s[i] - 'A', b = s[i + 1] - 'A';
        mp[a * 26 + b]++;
    }
    int p = 0;
    for(int i = 0; i < 26 * 26; i++){
        if(mp[i] > mp[p]){
            p = i;
        }
    }
    int a = p / 26, b = p % 26;
    printf("%c%c\n", 'A' + a, 'A' + b);
    return 0;
}
