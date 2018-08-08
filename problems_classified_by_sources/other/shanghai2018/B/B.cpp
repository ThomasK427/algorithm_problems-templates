#include <bits/stdc++.h>
using namespace std;

void process(int x){
    vector<int> v;
    int sum = 0;
    for(int i = 1; i * i <= x; i++){
        if(x % i == 0){
            sum += i;
            v.push_back(i);
            int j = x / i;
            if(j != x && j != i){
                sum += j;
                v.push_back(j);
            }
        }
    }
    if(sum == x){
        sort(v.begin(), v.end());
        printf("%d = %d", x, v[0]);
        for(int i = 1; i < v.size(); i++){
            printf(" + %d", v[i]);
        }
        putchar('\n');
    }else{
        puts("Not perfect.");
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int kase = 1; kase <= T; kase++){
        int x;
        scanf("%d", &x);
        printf("Case %d: ", kase);
        process(x);
    }
    return 0;
}
