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
    gets(str);
    int n = strlen(str), cnt = 0;
    bool flag = false;
    for(int i = 0; i < n; i++){
        if(str[i] == '1'){
            flag = true;
        }
        else{
            if(flag){
                if(str[i] == '0'){
                    cnt++;
                }
            }
        }
    }
    if(cnt >= 6){
        puts("yes");
    }
    else{
        puts("no");
    }
    return 0;
}
