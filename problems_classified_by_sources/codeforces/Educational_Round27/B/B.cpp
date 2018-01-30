#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int ar[maxn];
int br[maxn];

int main()
{
    //freopen("test.txt", "r", stdin);
    char str[10];
    scanf("%s", str);
    for(int i = 0; i < 6; i++){
        ar[i] = str[i] - '0';
    }
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < 3; i++){
        sum1 += ar[i];
        sum2 += ar[i+3];
    }
    if(sum1 == sum2){
        puts("0");
    }
    else if(sum1 < sum2){
        for(int i = 0; i < 3; i++){
            br[i] = 9 - ar[i];
        }
        for(int i = 3; i < 6; i++){
            br[i] = ar[i];
        }
        sort(br, br + 6);
        int dist = sum2 - sum1;
        int cnt = 0, p = 5;
        while(dist > 0){
            dist -= br[p--];
            cnt++;
        }
        printf("%d\n", cnt);
    }
    else{
        for(int i = 0; i < 3; i++){
            br[i] = ar[i];
        }
        for(int i = 3; i < 6; i++){
            br[i] = 9 - ar[i];
        }
        sort(br, br + 6);
        int dist = sum1 - sum2;
        int cnt = 0, p = 5;
        while(dist > 0){
            dist -= br[p--];
            cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
