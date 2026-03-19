#include <stdio.h>
#define dv 1000000000
#define rep(i,a,b) for(int i=a;i<b;i++)

int dp[201][201] = {0,}; // [수의 최대 개수][대상 정수]

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    rep(i,0,K) {
        rep(j,0,N+1) {
            if (i == 0) {
                dp[i][j] = 1;
                continue;
            }
            rep(k, 0, j+1) dp[i][j] = (dp[i][j] + dp[i-1][k]) % dv;
        }
    }

    printf("%d", dp[K-1][N]);
    return 0;
}