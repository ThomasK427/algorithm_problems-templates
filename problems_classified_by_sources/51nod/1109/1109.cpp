#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    queue<int> que;
    que.push(1);
    int x = 0;
    while(true){
        int u = que.front();
        que.pop();
        x++;
        if(u % N == 0){
            stack<int> s;
            while(x){
                s.push(x % 2);
                x /= 2;
            }
            while(!s.empty()){
                printf("%d", s.top());
                s.pop();
            }
            putchar('\n');
            break;
        }
        que.push(u * 10 % N);
        que.push((u * 10 + 1) % N);
    }
    return 0;
}
