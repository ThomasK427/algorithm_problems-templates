#include <bits/stdc++.h>
using namespace std;

int main()
{
    int M;
    cin >> M;
    if(M <= 153){
        cout << 153 << endl;
    }
    else if(M <= 370){
        cout << 370 << endl;
    }
    else if(M <= 371){
        cout << 371 << endl;
    }
    else if(M <= 407){
        cout << 407 << endl;
    }
    else{
        cout << 1634 << endl;
    }
    return 0;
}
