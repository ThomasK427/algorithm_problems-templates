#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

int a[maxn][2];
bool judge[10];
int n;

//思路：模拟三种数据结构进行操作，看是否符合，由此进行判断
bool JudgeStack()
{
    stack<int> s;
    for(int i = 0; i < n; i++){
        if(a[i][0] == 1){
            s.push(a[i][1]);
        }
        else{
            if(s.empty()){
                return false;
            }
            else{
                int x = s.top();
                s.pop();
                if(x != a[i][1]){
                    return false;
                }
            }
        }
    }
    return true;
}

bool JudgeQueue()
{
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(a[i][0] == 1){
            q.push(a[i][1]);
        }
        else{
            if(q.empty()){
                return false;
            }
            else{
                int x = q.front();
                q.pop();
                if(x != a[i][1]){
                    return false;
                }
            }
        }
    }
    return true;
}

bool JudgePriorityQueue()
{
    priority_queue<int> pq;
    for(int i = 0; i < n; i++){
        if(a[i][0] == 1){
            pq.push(a[i][1]);
        }
        else{
            if(pq.empty()){
                return false;
            }
            else{
                int x = pq.top();
                pq.pop();
                if(x != a[i][1]){
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    freopen("test.txt", "r", stdin);
    while(~scanf("%d", &n)){
        for(int i = 0; i < n; i++){
            scanf("%d%d", &a[i][0], &a[i][1]);
        }
        memset(judge, false, sizeof(judge));
        judge[0] = JudgeStack();
        judge[1] = JudgeQueue();
        judge[2] = JudgePriorityQueue();
        int cnt = 0, p = -1;
        for(int j = 0; j < 3; j++){
            if(judge[j]){
                cnt++;
                p = j;
            }
        }
        if(cnt == 0){
            printf("impossible\n");
        }
        else if(cnt >= 2){
            printf("not sure\n");
        }
        else{
            if(p == 0){
                printf("stack\n");
            }
            else if(p == 1){
                printf("queue\n");
            }
            else{
                printf("priority queue\n");
            }
        }
    }
    return 0;
}
