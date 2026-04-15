#include <stdio.h>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int dp[50001] = {0,1,2,3};

int main() {
    int N;
    scanf("%d", &N);
    rep(i,1,N+1) {
        dp[i] = 4;
        for (int j=1; j*j<=i; j++) {
            dp[i] = min(dp[i], dp[i-j*j]+1);
        }
    }
    printf("%d", dp[N]);
    return 0;
}