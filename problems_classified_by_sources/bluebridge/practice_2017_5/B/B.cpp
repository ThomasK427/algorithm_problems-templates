#include <bits/stdc++.h>
using namespace std;

int maxx = min(2471 / 11, 2739 / 13);
int maxy = min(2471 / 13, 2739 / 17);
int maxz = min(2471 / 17, 2739 / 11);

int main()
{
    int ans = 0x3f3f3f3f;
    for(int x = 1; x <= maxx; x++){
        for(int y = 1; y <= maxy; y++){
            for(int z = 1; z <= maxz; z++){
                if(11 * x + 13 * y + 17 * z == 2471 && 13 * x + 17 * y + 11 * z == 2739){
                    ans = min(ans, x + y + z);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
