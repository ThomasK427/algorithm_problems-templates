/**
*������51nod1385
*����һ��n,Ҫ���ҳ�һ����̵��ַ���S��ʹ������1��n����������S�������С�
*����n=10����ôS="1234056789"��ʱ�������������ġ����ʱ��S�ĳ�����10��
*���ڸ���һ��n��Ҫ��������S�ĳ��ȡ�1<=n<=1e10000
*
*ÿ��ѭ���ڰ�1, 21, 321, 4321, 54321, 654321, 7654321, 87654321, 987654321, 9876543210���������ŵ�
*
*/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;

char str[maxn];
int n;

bool check(int x){
    for(int i = 0; i < n; i++){
        if(str[i] > (x + '0')){
            return true;
        }
        else if(str[i] < (x + '0')){
            return false;
        }
    }
    return true;
}

int main()
{
    gets(str);
    n = strlen(str);
    int ans = (n - 1) * 10;     //������ѭ���ڵĸ���
    int t = 0;
    for(int i = 1; i <= 9; i++){
        if(check(i)){   //���㲻��ѭ����ʱ������һλ
            t = i;
        }
        else{
            break;
        }
    }
    ans += t;
    printf("%d\n", ans);
    return 0;
}
