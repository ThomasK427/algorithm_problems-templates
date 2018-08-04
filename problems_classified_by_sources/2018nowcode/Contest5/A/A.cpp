#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;

int s[maxn], c[maxn];
double v[maxn];
int n, k;

bool check(double x){
    for(int i = 0; i < n; i++){
        v[i] = (s[i] - x) * c[i];
    }
    sort(v, v + n);
    reverse(v, v + n);
    double sum = 0;
    for(int i = 0; i < n - k; i++){
        sum += v[i];
    }
    return sum >= 0.0;
}

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", s + i);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", c + i);
    }
    double low = 0, high = 1000, ans = 0;
    for(int i = 0; i < 200; i++){
        double mid = (low + high) / 2;
        if(check(mid)){
            low = mid;
            ans = mid;
        }else{
            high = mid;
        }
    }
    printf("%.7f\n", ans);
    return 0;
}
