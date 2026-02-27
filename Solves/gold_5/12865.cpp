#include <stdio.h>
int dp[2][100001] = {0};

int main() {
    int N,K;
    scanf("%d %d", &N, &K);
    for (int i=1;i<=N;i++) {
        int w,v;
        scanf("%d %d", &w, &v);
        for (int j=1;j<=K;j++) {
            dp[i%2][j] = dp[(i+1)%2][j];
            if (j-w<0) continue;
            if (dp[(i+1)%2][j] < dp[(i+1)%2][j-w]+v) dp[i%2][j] = dp[(i+1)%2][j-w]+v;
        }
    }
    printf("%d", dp[N%2][K]);
    return 0;
}