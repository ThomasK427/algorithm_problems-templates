#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

char str[maxn];
char g[100][100] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int main()
{
    scanf("%s", str);
    int sum = 0, n = strlen(str);
    for(int i = 0; i < n; i++){
        sum += str[i] - '0';
    }
    if(sum == 0){
        puts(g[0]);
        return 0;
    }
    stack<int> s;
    while(sum){
        s.push(sum % 10);
        sum /= 10;
    }
    while(!s.empty()){
        printf("%s", g[s.top()]);
        s.pop();
        if(s.empty()){
            printf("\n");
        }
        else{
            printf(" ");
        }
    }
    return 0;
}
