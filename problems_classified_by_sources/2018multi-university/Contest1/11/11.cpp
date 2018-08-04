#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;

double resolve(char* p){
    int sn = (*p == '+' ? 1 : -1);
    double a = 0, b = 0, xp = 1;
    bool flag = true;
    while(*(++p) != '\0'){
        if(*p == '.'){
            flag = false;
            continue;
        }
        if(flag){
            a = a * 10 + (*p - '0');
        }else{
            b = b * 10 + (*p - '0');
            xp *= 10;
        }
    }
    double res = sn * (a + b / xp);
    return res;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        int a, b;
        scanf("%d%d", &a, &b);
        int t = a * 60 + b;
        char buf[20];
        scanf("%s", buf);
        double d = resolve(buf + 3);
        t += floor((d - 8) * 60 + eps);
        t = (t + 24 * 60) % (24 * 60);
        a = t / 60;
        b = t % 60;
        printf("%02d:%02d\n", a, b);
    }
    return 0;
}
