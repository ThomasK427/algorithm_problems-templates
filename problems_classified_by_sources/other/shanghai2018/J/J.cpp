#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000005;

int a[maxn], s[maxn];

bool check(int x){
    int y = x, sum = 0;
    while(y){
        sum += y % 10;
        y /= 10;
    }
    return x % sum == 0;
}

int f(int n){
    if(n <= 10){
        return n;
    }
    double c = 14.0 / 27.0 * log(10), o = 0.55 - 0.025 * log(n);;
    int ans = (c + o) * n / log(n);
    return ans;
}

int main()
{

    int N = 1000000;
    s[0] = 0;
    double c = 14.0 / 27.0 * log(10), o = 0.35;
    for(int i = 1; i <= N; i++){
        if(check(i)){
            a[i] = 1;
        }else{
            a[i] = 0;
        }
        s[i] = s[i - 1] + a[i];
       // cout << i << " " << s[i] << " " << f(i) << endl;
//        if(i % 1000 == 0){
//            double a = s[i] * log(i) / i - c;
//            double b = 0.5 - 0.025 * log(i);
//            double c = a - b;
//            cout << c << endl;
//        }
    }
    return 0;
}
