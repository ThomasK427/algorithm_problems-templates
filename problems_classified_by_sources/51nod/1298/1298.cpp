#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        double xc, yc, R;
        scanf("%lf%lf%lf", &xc, &yc, &R);
        int a = 0, b = 0, c = 0;
        double x, y;
        for(int i = 0; i < 3; i++){
            scanf("%lf%lf", &x, &y);
            double L = sqrt((x - xc) * (x - xc) + (y - yc) * (y - yc));
            if(fabs(R - L) < eps){
                b++;
            }
            else if(L < R){
                a++;
            }
            else{
                c++;
            }
        }
        if(a == 3 || c == 3){
            puts("No");
        }
        else{
            puts("Yes");
        }
    }
    return 0;
}
