/**
51nod 1179
*����N�����������ҳ�N��������֮�����Լ�������ֵ�����磺N = 4��
*4����Ϊ��9 15 25 16������֮�����Լ�������ֵ��15ͬ25�����Լ��5��
*
*Input
*
*��1�У�һ����N����ʾ������������������(2 <= N <= 50000)
*��2 - N + 1�У�ÿ��1��������Ӧ�����������.(1 <= S[i] <= 1000000)
*
*Output
*
*�������֮�����Լ�������ֵ��
**/

/**
*����s[i]���Ǻܴ󣬿�����һ��10^6��Ͱͳ��ÿ���������˶��ٴΣ���Ϊar[s[i]]��
*����ö�ٴ�ans����Լ��ans�����ĸ���cnt = sum{ar[kx]}(k����������kx<=max{s[i]})��
*���cnt>=2˵��x�������Ĺ�Լ�������������ʱ�临�Ӷ���O( max{s[i]}*log(max{s[i]}) )��
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;

int ar[maxn];

int main()
{
    int N, x, mx = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &x);
        ar[x]++;
        mx = max(mx, x);
    }
    for(int ans = mx; ans >= 1; ans--){     //����ö�ٴ�
        int cnt = 0;
        for(int i = 1; ans * i <= mx; i++){
            cnt += ar[ans * i];
            if(cnt >= 2){
                break;
            }
        }
        if(cnt >= 2){
            printf("%d\n", ans);
            break;
        }
    }
    return 0;
}
