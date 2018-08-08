#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const ld PI = acos(-1.0);
const ld eps = 1e-10;

int cmp(ld a, ld b){
    if(fabs(a - b) < eps){
        return 0;
    }else if(a < b){
        return -1;
    }else{
        return 1;
    }
}

ld dist(ld x, ld y){
    return sqrt(x * x + y * y);
}

int main()
{
    //freopen("test.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--){
        int m, RR;
        scanf("%d%d", &m, &RR);
        ld R = RR;
        double ans = 2.0 * PI * R;
        for(int i = 0; i < m; i++){
            int xx, yy, rr;
            scanf("%d%d%d", &xx, &yy, &rr);
            ld x = xx, y = yy, r = rr, d = dist(x, y);
            if(cmp(d + r, R) < 0){ //包含在大圆内
                continue;
            }else if(cmp(d - r, R) >= 0){  //相离或外切
                continue;
            }else if(cmp(d + r, R) == 0){  //内切
                ans += 2.0 * PI * r;
            }else{  //相交
                ld alpha = 2.0 * acos((d * d + r * r - R * R) / (2.0 * d * r));
                ld beta = 2.0 * acos((d * d + R * R - r * r) / (2.0 * d * R));
                ans = ans + alpha * r - beta * R;
            }
        }
        printf("%.10f\n", double(ans));
    }
    return 0;
}
