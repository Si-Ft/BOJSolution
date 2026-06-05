#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

int main() {
    int N, A[1001];
    int dp[1001] = {0};
    scanf("%d", &N);
    rep(i,0,N) scanf("%d", &A[i]);
    dp[0] = 1;

    rep(i,1,N) {
        dp[i] = 1;
        rep(j,0,i) {
            // i번째 수열의 값이 j번째 수열의 값보다 크다면 비교 대상이 됨.
            if (A[j] < A[i]) {
                // 현재 수를 포함하는 가장 긴 증가수열을 현재 위치에 갱신
                if (dp[j]+1 > dp[i]) dp[i] = dp[j]+1;
            }
        }
    }
    int max = 0;
    rep(i,0,N) if (dp[i] > max) max = dp[i];
    printf("%d\n", max);
    return 0;
}