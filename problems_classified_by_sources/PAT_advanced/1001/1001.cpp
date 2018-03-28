#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;

char str[maxn];

int main()
{
    int a, b, sum;
    scanf("%d%d", &a, &b);
    sum = a + b;
    if(sum == 0){
        puts("0");
    }
    else{
        bool flag = sum < 0;
        sum = abs(sum);
        queue<int> que;
        while(sum){
            que.push(sum % 10);
            sum /= 10;
        }
        int c = 0, n = 0;
        while(!que.empty()){
            int u = que.front();
            que.pop();
            str[n++] = u + '0';
            c = (c + 1) % 3;
            if(c == 0){
                str[n++] = ',';
            }
        }
        if(c == 0){
            n--;
        }
        if(flag){
            str[n++] = '-';
        }
        reverse(str, str + n);
        str[n] = '\0';
        puts(str);
    }
    return 0;
}
