#include <cstdio>
using namespace std;
const int maxn = 1000005;

int ar[maxn], que[maxn], minans[maxn], maxans[maxn];

int Scan()
{   //  输入外挂
    int res = 0, flag = 0;
    char ch;
    if ((ch = getchar()) == '-')
    {
        flag = 1;
    }
    else if(ch >= '0' && ch <= '9')
    {
        res = ch - '0';
    }
    while ((ch = getchar()) >= '0' && ch <= '9')
    {
        res = res * 10 + (ch - '0');
    }
    return flag ? -res : res;
}

void Out(int a)
{   //  输出外挂
    if (a < 0)
    {
        putchar('-');
        a = -a;
    }
    if (a >= 10)
    {
       Out(a / 10);
    }
    putchar(a % 10 + '0');
}

int main()
{
    int n = Scan(), k = Scan();
    for(int i = 1; i <= n; i++){
        ar[i] = Scan();
    }
    int s = 1, t = 0;
    for(int i = 1; i <= n; i++){
        while(s <= t && i - que[s] + 1 > k){
            s++;
        }
        while(s <= t && ar[que[t]] <= ar[i]){
            t--;
        }
        que[++t] = i;
        maxans[i] = ar[que[s]];
    }
    s = 1;
    t = 0;
    for(int i = 1; i <= n; i++){
        while(s <= t && i - que[s] + 1 > k){
            s++;
        }
        while(s <= t && ar[que[t]] >= ar[i]){
            t--;
        }
        que[++t] = i;
        minans[i] = ar[que[s]];
    }
    for(int i = k; i <= n; i++){
        Out(minans[i]);
        putchar(i == n ? '\n' : ' ');
    }
    for(int i = k; i <= n; i++){
        Out(maxans[i]);
        putchar(i == n ? '\n' : ' ');
    }
    return 0;
}
