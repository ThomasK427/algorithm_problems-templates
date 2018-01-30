#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 1000005;

int ar[maxn];

int main()
{
    //freopen("test.txt", "r", stdin);
    int n, sum = 0;
    bool flag = false;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", ar + i);
        sum += ar[i];
        if(ar[i] & 1){
            flag = true;
        }
    }
    if((sum & 1) || flag){
        puts("First");
    }
    else{
        puts("Second");
    }
    return 0;
}
