#include <stdio.h>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int dp[1001][2] = {0}; 

int main() {
    int C,N; // 목표 가치, 보석의 개수
    scanf("%d %d", &C, &N);

    rep(i,1,C+1) dp[i][0] = 1<<30;
    rep(i,1,N+1) {
        int weight, val;
        scanf("%d %d", &weight, &val);
        rep(j,1,C+1) {
            dp[j][i%2] = min(dp[j][(i+1)%2], ((j-1)/val + 1) * weight);
            if (j-val < 0) continue;
            dp[j][i%2] = min(dp[j][i%2], dp[j-val][i%2] + weight);
        }
    }

    printf("%d", dp[C][N%2]);

    return 0;
}