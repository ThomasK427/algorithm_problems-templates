#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;

int ar[maxn];

int main()
{
    int ans = 0;
    for(int i = 1; i <= 13; i++){
        int k = 0;
        for(int j = 1; j <= 13; j++){
            if(i == j){
                continue;
            }
            else{
                ar[++k] = j;
            }
        }
        do{
            bool b1 = (ar[1] * ar[2] + ar[3] * ar[4] == ar[5] * ar[6]);
            bool b2 = (ar[7] * ar[8] - ar[9] * ar[10] == ar[11] * ar[12]);
            if(b1 && b2){
                ans++;
            }
        }while(next_permutation(ar + 1, ar + 13));
    }
    printf("%d\n", ans);
    return 0;
}
