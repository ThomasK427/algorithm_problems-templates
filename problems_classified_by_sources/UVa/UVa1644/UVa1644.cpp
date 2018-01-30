#include <bits/stdc++.h>
using namespace std;
const int maxn = 1300005;

//����ɸ��O(n)
bool valid[maxn];    //valid[i]��¼i�Ƿ�Ϊ����
int prime[maxn];     //prime[i]��¼��i������
int tot;    //��¼�����ĸ���

void getPrime(int n){   //��һ��С�ڵ���n��������
    for(int i = 2; i <= n; i++){
        valid[i] = true;
    }
    tot = 0;
    for(int i = 2; i <= n; i++){
        if(valid[i]){
            prime[++tot] = i;
        }
        for(int j = 1; j <= tot && i * prime[j] <= n; j++){
            valid[i * prime[j]] = false;
            if(i % prime[j] == 0){
                break;
            }
        }
    }
}

int main()
{
    getPrime(1300000);
    int x;
    while(~scanf("%d", &x) && x){
        int p = lower_bound(prime + 1, prime + tot + 1, x) - prime;
        printf("%d\n", prime[p] == x ? 0 : prime[p] - prime[p - 1]);
    }
    return 0;
}
