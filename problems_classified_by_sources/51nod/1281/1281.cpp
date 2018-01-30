#include <stdio.h>
const int maxn = 50005;

int ar[maxn], br[maxn];
int N, M;

int check(int K){
    if(K == 0){
        return 1;
    }
    else if(K > M){
        return 0;
    }
    else{
        int cur = br[0], cnt = 1;
        for(int i = 1; i < M; i++){
            if(br[i] - cur >= K){
                cnt++;
                cur = br[i];
            }
        }
        if(cnt >= K){
            return 1;
        }
        else{
            return 0;
        }
    }
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", ar + i);
    }
    M = 0;
    for(int i = 1; i < N - 1; i++){
        if(ar[i] > ar[i - 1] && ar[i] > ar[i + 1]){
            br[M++] = i;
        }
    }
    int low = 0, high = M + 1;
    while(low < high){
        int mid = low + high + 1 >> 1;
        if(check(mid)){
            low = mid;
        }
        else{
            high = mid - 1;
        }
    }
    printf("%d\n", low);
    return 0;
}
