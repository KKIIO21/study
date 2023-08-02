#include <stdio.h>

#define inf 987654321;

typedef struct knapsack{
    int a, b;
}knapsack;

knapsack ww[101];

int bag(int now, int weight);
int max(int x, int y);

int dp[101][100001] = {0};
int n, k;

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &ww[i].a, &ww[i].b);
    }
    printf("%d", bag(0, 0));

}

int bag(int now, int weight){ 

    int tmp1, tmp2, ans;
    if(weight > k){
        return (-1) * inf;
    }
    if(now == n){
        return 0;
    }
    if(dp[now][weight] != 0){ 
        return dp[now][weight];
    }
    tmp1 = ww[now].b + bag(now + 1, weight + ww[now].a);
    tmp2 = bag(now + 1, weight);

    ans = max(tmp1, tmp2);
    dp[now][weight] = ans; 
 
    return ans;
}

int max(int x, int y){
    return x > y ? x : y;
}
