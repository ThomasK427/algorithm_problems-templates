#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 100005;

char str[maxn], ans[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        scanf("%s", str);
        if(n % 4 == 0){
            for(int i = 0; i < n; i++){
                if(i % 4 == 0 || i % 4 == 3){
                    ans[i] = '0';
                }
                else{
                    ans[i] = '1';
                }
            }
            for(int i = 0; i < n; i++){
                if(str[i] == '0'){
                    str[i] = ans[i];
                }
                else{

                }
            }
        }
        else if((n + 1) % 4 == 0){
            int a = n / 2, b = a + 1;
            while(a >= 0){
                ans[a] = '0';
                if(a - 1 >= 0){
                    ans[a - 1] = '1';
                }
                a -= 2;
            }
            while(b < n){
                ans[b] = '0';
                if(b + 1 < n){
                    ans[b + 1] = '1';
                }
                b += 2;
            }
        }
        else{
            puts("-1");
        }
    }
    return 0;
}
