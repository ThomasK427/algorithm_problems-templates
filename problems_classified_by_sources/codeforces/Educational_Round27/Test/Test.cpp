#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const LL inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1005;

int ar[maxn];

void GetNext(char* p, int next[])
{
    int plen = strlen(p);
    next[0] = -1;
    int k = -1;
    int j = 0;
    while(j < plen - 1){
        if(k == -1 || p[j] == p[k]){
            ++k;
            ++j;
            next[j] = k;
        }
        else{
            k = next[k];
        }
    }
}

int main()
{
    //freopen("test.txt", "r", stdin);
    char str[100];
    while(cin >> str)
    {
        GetNext(str, ar);
        int len = strlen(str);
        for(int i = 0; i < len; i++){
            cout << ar[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
