#include <bits/stdc++.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;

int ar[100];

int main()
{
    //freopen("test.txt", "r", stdin);
    int n;
    while(~scanf("%d", &n)){
        for(int i = 0; i < n; i++){
            scanf("%d", ar + i);
        }
        if(n == 1){
            if(ar[0] == 0){
                puts("UP");
            }
            else if(ar[0] == 15){
                puts("DOWN");
            }
            else{
                puts("-1");
            }
        }
        else{
            if(ar[n-1] == 0){
                puts("UP");
            }
            else if(ar[n-1] == 15){
                puts("DOWN");
            }
            else{
                if(ar[n-1] > ar[n-2]){
                    puts("UP");
                }
                else{
                    puts("DOWN");
                }
            }
        }
    }
    return 0;
}



