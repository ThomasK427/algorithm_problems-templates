#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;

int a[maxn], b[maxn], left1[maxn], right0[maxn];

int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d%d", a + i, b + i);
    }
//    left1[0] = 0;
//    right0[N + 1] = 0;
//    for(int i = 1; i <= N; i++){
//        if(b[i] == 0){
//            left1[i] = left1[i - 1];
//        }
//        else{
//            left1[i] = max(left1[i - 1], a[i]);
//        }
//    }
//    for(int i = N; i >= 1; i--){
//        if(b[i] == 0){
//            right0[i] = max(right0[i + 1], a[i]);
//        }
//        else{
//
//            right0[i] = right0[i + 1];
//        }
//    }
//    int ans = 0, sum = N;
//    for(int i = 1; i <= N; i++){
//        if(b[i] == 0){
//            if(left1[i - 1] > a[i]){
//                //ans++;
//                sum--;
//            }
//        }
//        else{
//            if(right0[i + 1] > a[i]){
//                //ans++;
//                sum--;
//            }
//        }
//    }
//    printf("%d\n", sum);
    return 0;
}
