#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        sum += x;
    }
    printf("%.2f\n", double(sum) / n);
    return 0;
}
