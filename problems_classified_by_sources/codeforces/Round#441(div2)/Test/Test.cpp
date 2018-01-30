#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int deccount(int x){
    int sum = 0;
    while(x){
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);
    stack<int> s;
    for(int i = n; i >= n - 100 && i >= 0; i--){
        if(i + deccount(i) == n){
            s.push(i);
        }
    }
    printf("%d\n", (int)s.size());
    while(!s.empty()){
        printf("%d ", s.top());
        s.pop();
    }
    putchar('\n');
    return 0;
}
