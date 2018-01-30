#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;

int ar[maxn], br[maxn], mp[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", ar + i);
    }
    for(int i = 1; i <= n; i++){
        scanf("%d", br + i);
        mp[br[i]] = i;
    }

    return 0;
}
