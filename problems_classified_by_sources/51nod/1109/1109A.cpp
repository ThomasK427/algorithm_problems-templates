#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

int mod[maxn];

int main()
{
    int N;
    mod[0] = 1;
    for(int i = 1; i <= 1000; i++){
        mod[i] = mod[i - 1] * 10 % N;
    }

    return 0;
}
