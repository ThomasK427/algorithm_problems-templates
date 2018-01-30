#include <cstdio>
const int maxn = 1400000;

bool valid[maxn];
int ans[maxn];
int tot = 0;

void getPrime()
{
    tot = 0;
    for(int i = 0; i < maxn; i++){
        valid[i] = true;
    }
    for(int i = 2; i < maxn; i++){
        if(valid[i]){
            tot++;
            ans[tot] = i;
        }
        for(int j = 1; (j <= tot) && (i * ans[j] < maxn); j++){
            valid[i * ans[j]] = false;
            if(i % ans[j] == 0){
                break;
            }
        }
    }
}

int leftBound(int x)
{
    int low = 1, high = tot;
    while(low < high){
        int mid = (low + high + 1) >> 1;
        if(ans[mid] <= x){
            low = mid;
        }
        else{
            high = mid - 1;
        }
    }
    return ans[low];
}

int rightBound(int x)
{
    int low = 1, high = tot;
    while(low < high){
        int mid = (low + high) >> 1;
        if(ans[mid] >= x){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }
    return ans[high];
}

int main()
{
    getPrime();
    int n;
    while(~scanf("%d", &n) && n){
        printf("%d\n", rightBound(n) - leftBound(n));
    }
    return 0;
}
