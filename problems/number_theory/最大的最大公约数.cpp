/**
51nod 1179
*给出N个正整数，找出N个数两两之间最大公约数的最大值。例如：N = 4，
*4个数为：9 15 25 16，两两之间最大公约数的最大值是15同25的最大公约数5。
*
*Input
*
*第1行：一个数N，表示输入正整数的数量。(2 <= N <= 50000)
*第2 - N + 1行：每行1个数，对应输入的正整数.(1 <= S[i] <= 1000000)
*
*Output
*
*输出两两之间最大公约数的最大值。
*/

/**
*由于s[i]不是很大，可以用一个10^6的桶统计每个数出现了多少次，记为ar[s[i]]。
*倒着枚举答案ans，有约数ans的数的个数cnt = sum{ar[kx]}(k是正整数且kx<=max{s[i]})，
*如果cnt>=2说明x就是最大的公约数。这个做法的时间复杂度是O( max{s[i]}*log(max{s[i]}) )。
*/

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
    for(int ans = mx; ans >= 1; ans--){     //逆序枚举答案
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
