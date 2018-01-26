/**
*51nod 1191
*有N只兔子，每只有一个血量B[i]，需要用箭杀死免子。有M种不同类型的箭可以选择，
*每种箭对兔子的伤害值分别为D[i]，价格为P[i](1 <= i <= M)。假设每种箭只能使用
*一次，每只免子也只能被射一次，计算要消灭地图上的所有兔子最少需要多少Q币。如
*不能杀死所有兔子，请输出No Solution。
*特别说明：1、当箭的伤害值大于等于兔子的血量时，能将兔子杀死；2、血量B[i]，
*箭的伤害值D[i]，箭的价格P[i]，均小于等于100000。
*
*Input
*
*第1行：两个整数N，M，中间用空格分隔（1 <= N, M <= 50000），分别表示兔子的个数和箭的种类。
*第2 - N + 1行：每行1个正整数(共N行)，表示兔子的血量B[i]（1 <= B[i] <= 100000）。
*第N + 2 - N + M + 1行：每行2个正整数(共M行)，中间用空格分隔，表示箭所能造成的伤害值D[i]，和需要花费的Q币P[i]（1 <= D[i], P[i] <= 100000）。
*
*Output
*
*输出最少需要多少Q币才能消灭所有的兔子。如果不能杀死所有兔子，请输出"No Solution"。
*
*/

//贪心思路：从每只兔子考虑（按血量降序排列），用价值最小的箭射这只兔子。

#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;

struct Node{
    int D, P;
    friend bool operator<(const Node& a, const Node& b){
        return a.P > b.P;
    }
}E[maxn];
int B[maxn];

bool cmp(const Node& a, const Node& b){
    return a.D > b.D;
}

priority_queue<Node> que;

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++){
        scanf("%d", B + i);
    }
    for(int i = 0; i < M; i++){
        scanf("%d%d", &E[i].D, &E[i].P);
    }
    //兔子按血量降序排序
    sort(B, B + N);
    reverse(B, B + N);
    //箭按伤害值降序排序
    sort(E, E + M, cmp);
    long long ans = 0;
    int p = 0;
    bool flag = true;
    for(int i = 0; i < N; i++){
        //把能杀死兔子的箭都放进优先队列
        //可以保证上一次放入优先队列的箭一定可以杀死下一个考虑的兔子
        while(p < M && E[p].D >= B[i]){
            que.push(E[p]);
            p++;
        }
        //从可以杀死兔子的箭中选择价值最小
        if(que.empty()){
            flag = false;
            break;
        }
        ans += que.top().P;
        que.pop();
    }
    if(flag){
        printf("%lld\n", ans);
    }
    else{
        puts("No Solution");
    }
    return 0;
}
