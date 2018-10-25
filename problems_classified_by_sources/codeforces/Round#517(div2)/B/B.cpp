#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
const int maxn = 100005;

int a[maxn], b[maxn], t[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        scanf("%d", a + i);
    }
    for(int i = 1; i < n; i++){
        scanf("%d", b + i);
    }
    bool flag = false;
    for(t[1] = 0; t[1] < 4; t[1]++){
        int i = 1;
        for(; i < n; i++){
            for(t[i + 1] = 0; t[i + 1] < 4; t[i + 1]++){
                if((t[i] | t[i + 1]) == a[i] && (t[i] & t[i + 1]) == b[i]){
                    break;
                }
            }
            if(t[i + 1] == 4){
                break;
            }
        }
        if(i == n){
            flag = true;
            break;
        }
    }
    if(flag){
        puts("YES");
        for(int i = 1; i <= n; i++){
            printf("%d%c", t[i], i == n ? '\n' : ' ');
        }
    }else{
        puts("NO");
    }
    return 0;
}
