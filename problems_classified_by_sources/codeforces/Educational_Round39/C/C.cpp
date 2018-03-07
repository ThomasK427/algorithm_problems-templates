#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 100005;

char s[maxn];
char t[] = "abcdefghijklmnopqrstuvwxyz";

int main()
{
    scanf("%s", s);
    int n = strlen(s);
    int i = 0, j = 0;
    while(i < n && j < 26){
        if(s[i] > t[j]){
            i++;
        }
        else{
            s[i++] = t[j++];
        }
    }
    puts(j == 26 ? s : "-1");
    return 0;
}
