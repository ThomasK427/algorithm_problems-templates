#include <bits/stdc++.h>
using namespace std;

int f(int p, int a){
    int b = int(ceil(log(a) / log(p)));
    return a / b;
}

int main()
{
    for(int p = 2; p <= 10; p++){
        for(int a = 2; a <= 30; a++){
            cout << f(p, a) << " ";
        }
        cout << endl;
    }
    return 0;
}
