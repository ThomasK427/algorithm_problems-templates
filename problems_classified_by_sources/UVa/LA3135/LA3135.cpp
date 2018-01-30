#include <bits/stdc++.h>
using namespace std;

struct Node{
    int Q_num, Period, Time;
    Node(int q, int p, int t):Q_num(q), Period(p), Time(t){}
    friend bool operator<(const Node& n1, const Node& n2){
        if(n1.Time != n2.Time){
            return n1.Time > n2.Time;
        }
        else{
            return n1.Q_num > n2.Q_num;
        }
    }
};

priority_queue<Node> pq;

int main()
{
    //freopen("test.txt", "r", stdin);
    char str[100];
    int q, p;
    while(~scanf("%s", str) && (str[0] != '#')){
        scanf("%d%d", &q, &p);
        pq.push(Node(q, p, p));
    }
    int k;
    scanf("%d", &k);
    while(k--){
        Node node = pq.top();
        pq.pop();
        printf("%d\n", node.Q_num);
        pq.push(Node(node.Q_num, node.Period, node.Time + node.Period));
    }
    return 0;
}
