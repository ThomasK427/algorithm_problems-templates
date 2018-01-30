#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;

priority_queue<int, vector<int>, greater<int> > pq;

int main()
{
    int N;
    while(~scanf("%d", &N)){
        while(!pq.empty()){
            pq.empty();
        }
        int x;
        while(N--){
            scanf("%d", &x);
            pq.push(x);
        }
        while(!pq.empty()){
            printf("%d\n", pq.top());
            pq.pop();
        }
    }
    return 0;
}
