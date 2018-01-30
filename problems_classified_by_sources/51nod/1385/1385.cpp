/**
*凑数字51nod1385
*给定一个n,要求找出一个最短的字符串S，使得所有1到n的整数都是S的子序列。
*比如n=10，那么S="1234056789"的时候，是满足条件的。这个时候S的长度是10。
*现在给出一个n，要求输出最短S的长度。1<=n<=1e10000
*
*每个循环节按1, 21, 321, 4321, 54321, 654321, 7654321, 87654321, 987654321, 9876543210构造是最优的
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
    int ans = (n - 1) * 10;     //计算满循环节的个数
    int t = 0;
    for(int i = 1; i <= 9; i++){
        if(check(i)){   //计算不满循环节时补到哪一位
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
