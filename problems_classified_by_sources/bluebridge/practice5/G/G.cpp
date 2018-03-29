#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    if(n > m){
        swap(n, m);
    }
    int ans = 0;
    if(n == 1){
        ans = m;
    }
    else if(n == 2){
        ans = (m / 4 * 2 + min(2, m % 4)) * 2;
    }
    else{
        ans = ((n + 1) / 2) * ((m + 1) / 2) + (n - (n + 1) / 2) * (m - (m + 1) / 2);
    }
    printf("%d\n", ans);
    return 0;
}
