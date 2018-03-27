#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

int sg[maxn];
int d[] = {1, 3, 7, 9};

int main()
{
    sg[0] = 0;
    for(int i = 0; i <= 1000; i++){
        unordered_set<int> st;
        for(int j = 0; j < 4; j++){
            int h = i - d[j];
            if(h >= 0){
                st.insert(sg[h]);
            }
            else{
                break;
            }
        }
        for(int j = 0; ; j++){
            if(!st.count(j)){
                sg[i] = j;
                break;
            }
        }
    }
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    if(sg[n + m + k]){
        puts("win");
    }
    else{
        puts("loss");
    }
    return 0;
}
