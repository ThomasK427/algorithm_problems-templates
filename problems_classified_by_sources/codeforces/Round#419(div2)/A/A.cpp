#include <bits/stdc++.h>
using namespace std;

bool check(int u, int v){
    int w = (u % 10) * 10 + (u / 10);
    return v == w;
}

int main()
{
    //freopen("test.txt", "r", stdin);
    int hh, mm;
    while(~scanf("%d:%d", &hh, &mm)){
        int cnt = 0;
        while(!check(hh, mm)){
            cnt++;
            mm++;
            if(mm == 60){
                hh++;
                mm = 0;
            }
            hh = hh % 24;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
