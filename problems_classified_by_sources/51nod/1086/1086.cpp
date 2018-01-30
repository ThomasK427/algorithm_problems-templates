/**
*
*��N����Ʒ��ÿ����Ʒ������ΪC1��C2......Cn��������ѡ���ɼ�����
*����ΪW�ı����ÿ����Ʒ�����ΪW1��W2......Wn��WiΪ��������
*��֮���Ӧ�ļ�ֵΪP1,P2......Pn��PiΪ���������󱳰��ܹ����ɵ�����ֵ��
*
*Input
*
*��1�У�2��������N��W�м��ÿո������NΪ��Ʒ�����࣬WΪ������������(1 <= N <= 100��1 <= W <= 50000)
*��2 - N + 1�У�ÿ��3��������Wi��Pi��Ci�ֱ�����Ʒ�������ֵ��������(1 <= Wi, Pi <= 10000�� 1 <= Ci <= 200)
*
*Output
*
*����������ɵ�����ֵ��
*
**/

/**
*���ر������⣺��һ������ΪC����Ʒ�ֽ�Ϊ����Ϊ1��2��4��8��...��2^k, C - 2^(k+1) + 1�Ķ������
*Ȼ�󵱳�0-1��������
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2005;
const int maxk = 50005;

int c[maxn], w[maxn], p[maxn];
LL dp[maxk];

vector<int> split(int x)
{
    vector<int> v;
    int p = 1;
    while(x >= p){
        v.push_back(p);
        x -= p;
        p *= 2;
    }
    if(x > 0){
        v.push_back(x);
    }
    return v;
}

int main()
{
    int N, W, M = 0, x, y, z;
    scanf("%d%d", &N, &W);
    for(int i = 1; i <= N; i++){
        scanf("%d%d%d", &x, &y, &z);
        vector<int> v = split(z);
        for(int j = 0; j < v.size(); j++){
            w[++M] = x * v[j];
            p[M] = y * v[j];
        }
    }
    for(int i = 1; i <= M; i++){
        for(int j = W; j >= w[i]; j--){
            dp[j] = max(dp[j], dp[j-w[i]] + LL(p[i]));
        }
    }
    printf("%lld\n", dp[W]);

    return 0;
}
