#include <cstdio>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 1005;

struct Node{
    double x, y, z;
    friend bool operator<(const Node& a, const Node& b){
        return a.z < b.z;
    }
}v[maxn];

double dist(double x1, double y1, double x2, double y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    int n, d, kase = 0;
    while(~scanf("%d%d", &n, &d) && (n || d)){
        bool flag = true;
        for(int i = 0; i < n; i++){
            scanf("%lf%lf", &v[i].x, &v[i].y);
            v[i].z = v[i].x + sqrt(d * d - v[i].y * v[i].y);
            if(v[i].y > d){
                flag = false;
            }
        }
        if(!flag){
            puts("-1");
            continue;
        }
        sort(v, v + n);
        double cur = -1e10;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(dist(v[i].x, v[i].y, cur, 0.0) > d){
                cur = v[i].z;
                cnt++;
            }
        }
        printf("Case %d: %d\n", ++kase, cnt);
    }
    return 0;
}
