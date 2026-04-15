#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define dv 10007

int main() {
    int dp[3] = {1,3};
    int N;
    scanf("%d", &N);
    if (N<=2) {
        printf("%d", dp[N-1]);
        return 0;
    }
    rep(i,2,N) {
        dp[i%3] = dp[(i-1)%3] + dp[(i-2)%3] * 2;
        dp[i%3] %= dv;
    }
    printf("%d", dp[(N-1)%3]);
    return 0;
}