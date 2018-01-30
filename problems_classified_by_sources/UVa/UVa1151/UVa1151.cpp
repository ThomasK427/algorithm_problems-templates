#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

struct Edge{
    int from, to, cost;
    friend bool operator<(const Edge& e1, const Edge& e2){
        return e1.cost > e2.cost;
    }
};

vector<Edge> v;

int main()
{

}
