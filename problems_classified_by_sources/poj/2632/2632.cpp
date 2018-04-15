#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 105;

int fy[] = {1, 0, -1, 0}, fx[] = {0, 1, 0, -1};

int g[maxn][maxn];
int x[maxn], y[maxn], d[maxn];

int main()
{
    int K;
    scanf("%d", &K);
    for(int kase = 0; kase < K; kase++){
        int A, B, N, M;
        scanf("%d%d%d%d", &A, &B, &N, &M);
        memset(g, 0, sizeof(g));
        for(int i = 1; i <= N; i++){
            scanf("%d%d", x + i, y + i);
            g[y[i]][x[i]] = i;
            getchar();
            char ch;
            scanf("%c", &ch);
            if(ch == 'N'){
                d[i] = 0;
            }
            else if(ch == 'E'){
                d[i] = 1;
            }
            else if(ch == 'S'){
                d[i] = 2;
            }
            else{
                d[i] = 3;
            }
        }
        int er = 0, rb = 0, rbt = 0;
        for(int i = 1; i <= M; i++){
            int robot, repeat;
            char action;
            scanf("%d", &robot);
            getchar();
            scanf("%c", &action);
            scanf("%d", &repeat);
            while((er == 0) && (repeat--)){
                if(action == 'L'){
                    d[robot] = (d[robot] - 1 + 4) % 4;
                }
                else if(action == 'R'){
                    d[robot] = (d[robot] + 1) % 4;
                }
                else{
                    g[y[robot]][x[robot]] = 0;
                    x[robot] += fx[d[robot]];
                    y[robot] += fy[d[robot]];
                    if(!(x[robot] >= 1 && x[robot] <= A && y[robot] >= 1 && y[robot] <= B)){
                        er = 1;
                        rb = robot;
                    }
                    else{
                        if(g[y[robot]][x[robot]]){
                            er = 2;
                            rb = robot;
                            rbt = g[y[robot]][x[robot]];
                        }
                        else{
                            g[y[robot]][x[robot]] = robot;
                        }
                    }
                }
            }
        }
        if(er == 0){
            puts("OK");
        }
        else if(er == 1){
            printf("Robot %d crashes into the wall\n", rb);
        }
        else{
            printf("Robot %d crashes into robot %d\n", rb, rbt);
        }
    }
    return 0;
}
