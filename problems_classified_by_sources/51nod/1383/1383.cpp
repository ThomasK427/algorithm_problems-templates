#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    LL p = 1;
    for(int i = 0; p <= 1000000; i++){
        cout << i << "\t" << p << endl;
        p *= 2;
    }
}
