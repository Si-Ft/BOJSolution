#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define dv 1000000000

int N;
int dp[10][100][1024] = {0}; //[수열의 마지막 숫자][숫자의 길이][비트마스크]
// 지금까지 사용한 숫자 -> 비트마스크

int main() {
    scanf("%d", &N);
    rep(i,0,N) {
        rep(j,0,10) {
            if (i==0 && j==0) {
                continue;
            }
            else if (i==0) {
                dp[j][i][1<<j] = 1;
                continue;
            }

            rep(k,0,1024) {
                if (j>0) dp[j][i][k|(1<<j)] += dp[j-1][i-1][k];
                dp[j][i][k|(1<<j)] %= dv;
                if (j<9) dp[j][i][k|(1<<j)] += dp[j+1][i-1][k];
                dp[j][i][k|(1<<j)] %= dv;
            }
        }
    }

    int ans = 0;
    rep(i,0,10) {
        ans += dp[i][N-1][1023];
        ans %= dv;
    }
    printf("%d", ans);
    return 0;
}