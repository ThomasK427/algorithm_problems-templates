#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100005;

char s[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    gets(s);
    sort(s, s + n);
    puts(s);
    return 0;
}
