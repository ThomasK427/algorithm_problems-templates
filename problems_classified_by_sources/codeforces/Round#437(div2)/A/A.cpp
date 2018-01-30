#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

char str[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    scanf("%s", str);
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n - 1; i++){
        if(str[i] == 'S' && str[i + 1] == 'F'){
            cnt1++;
        }
        else if(str[i] == 'F' && str[i + 1] == 'S'){
            cnt2++;
        }
    }
    if(cnt1 > cnt2){
        puts("YES");
    }
    else{
        puts("NO");
    }
    return 0;
}
