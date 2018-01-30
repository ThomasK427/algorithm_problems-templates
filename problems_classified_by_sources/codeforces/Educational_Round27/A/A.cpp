#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int ar[maxn];

int main()
{
    //freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= 2 * n; i++){
        scanf("%d", ar + i);
    }
    sort(ar + 1, ar + 2 * n + 1);

    if(ar[n+1] > ar[n]){
        puts("YES");
    }
    else{
        puts("NO");
    }
    return 0;
}
