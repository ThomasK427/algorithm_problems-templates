#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 1005;

int main()
{
    int cnt = 0;
    for(int i = 1; i <= 1000; i++){
        int c = 0;
        if(i % 3 == 0){
            c++;
        }
        if(i % 5 == 0){
            c++;
        }
        if(i % 7 == 0){
            c++;
        }
        if(c % 2 == 0){
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
