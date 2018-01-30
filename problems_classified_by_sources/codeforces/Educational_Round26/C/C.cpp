#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;

int x[maxn], y[maxn];

int main()
{
    int n, a, b;
    while(~scanf("%d%d%d", &n, &a, &b)){
        for(int i = 0; i < n; i++){
            scanf("%d%d", x + i, y + i);
        }
        int res = 0;
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                bool f1 = (x[i] + x[j] <= a) && (max(y[i], y[j]) <= b);
                bool f2 = (x[i] + x[j] <= b) && (max(y[i], y[j]) <= a);
                bool f3 = (x[i] + y[j] <= a) && (max(y[i], x[j]) <= b);
                bool f4 = (x[i] + y[j] <= b) && (max(y[i], x[j]) <= a);
                bool f5 = (y[i] + x[j] <= a) && (max(x[i], y[j]) <= b);
                bool f6 = (y[i] + x[j] <= b) && (max(x[i], y[j]) <= a);
                bool f7 = (y[i] + y[j] <= a) && (max(x[i], x[j]) <= b);
                bool f8 = (y[i] + y[j] <= b) && (max(x[i], x[j]) <= a);
                if(f1 || f2 || f3 || f4 || f5 || f6 || f7 || f8){
                    res = max(res, x[i] * y[i] + x[j] * y[j]);
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
