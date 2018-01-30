/*

��Nֻ���ӣ�ÿֻ��һ��Ѫ��B[i]����Ҫ�ü�ɱ�����ӡ���M�ֲ�ͬ���͵ļ�����ѡ��
ÿ�ּ������ӵ��˺�ֵ�ֱ�ΪD[i]���۸�ΪP[i](1 <= i <= M)������ÿ�ּ�ֻ��ʹ��
һ�Σ�ÿֻ����Ҳֻ�ܱ���һ�Σ�����Ҫ�����ͼ�ϵ���������������Ҫ����Q�ҡ���
����ɱ���������ӣ������No Solution��
�ر�˵����1���������˺�ֵ���ڵ������ӵ�Ѫ��ʱ���ܽ�����ɱ����2��Ѫ��B[i]��
�����˺�ֵD[i]�����ļ۸�P[i]����С�ڵ���100000��

Input

��1�У���������N��M���м��ÿո�ָ���1 <= N, M <= 50000�����ֱ��ʾ���ӵĸ����ͼ������ࡣ
��2 - N + 1�У�ÿ��1��������(��N��)����ʾ���ӵ�Ѫ��B[i]��1 <= B[i] <= 100000����
��N + 2 - N + M + 1�У�ÿ��2��������(��M��)���м��ÿո�ָ�����ʾ��������ɵ��˺�ֵD[i]������Ҫ���ѵ�Q��P[i]��1 <= D[i], P[i] <= 100000����

Output

���������Ҫ����Q�Ҳ����������е����ӡ��������ɱ���������ӣ������"No Solution"��

*/

//̰��˼·����ÿֻ���ӿ��ǣ���Ѫ���������У����ü�ֵ��С�ļ�����ֻ���ӡ�

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
    //���Ӱ�Ѫ����������
    sort(B, B + N);
    reverse(B, B + N);
    //�����˺�ֵ��������
    sort(E, E + M, cmp);
    long long ans = 0;
    int p = 0;
    bool flag = true;
    for(int i = 0; i < N; i++){
        //����ɱ�����ӵļ����Ž����ȶ���
        //���Ա�֤��һ�η������ȶ��еļ�һ������ɱ����һ�����ǵ�����
        while(p < M && E[p].D >= B[i]){
            que.push(E[p]);
            p++;
        }
        //�ӿ���ɱ�����ӵļ���ѡ���ֵ��С
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
