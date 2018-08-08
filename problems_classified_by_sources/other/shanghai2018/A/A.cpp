#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;

int x[maxn], y[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        srand(time(0));
        int n;
        double d;
        scanf("%d%lf", &n, &d);
        for(int i = 0; i < n; i++){
            scanf("%d%d", x + i, y + i);
        }
        bool flag = false;
        for(int t = 0; t < 200; t++){
            int a = rand() % n, b = rand() % n;
            while(a == b){
                b = rand() % n;
            }
            int m = 0;
            for(int i = 0; i < n; i++){
                if((y[i] - y[a]) * (x[b] - x[a]) == (y[b] - y[a]) * (x[i] - x[a])){
                    m++;
                }
            }
            if(m >= n * d){
                flag = true;
                break;
            }
        }
        puts(flag ? "Yes" : "No");
    }
    return 0;
}
