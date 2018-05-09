#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1005;

char str[maxn];

int main()
{
    scanf("%s", str);
    int n = strlen(str);
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++){
        if(str[i] == 'o'){
            cnt1++;
        }
        else{
            cnt2++;
        }
    }
    if(cnt1 == 0 || cnt2 % cnt1 == 0){
        puts("YES");
    }
    else{
        puts("NO");
    }
    return 0;
}
