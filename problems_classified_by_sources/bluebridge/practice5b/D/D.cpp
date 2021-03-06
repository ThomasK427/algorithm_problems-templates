#include <iostream>
using namespace std;

int pw(int x, int y, int p) {
    if (!y) {
        return 1;
    }
    int res = 1LL * pw(x, y / 2, p) * pw(x, y / 2, p) % p;
    if (y & 1) {
        res = res * x % p;
    }
    return res;
}

int main() {
    int x, y, p;
    cin >> x >> y >> p;
    cout << pw(x, y, p) << endl;
    return 0;
}
