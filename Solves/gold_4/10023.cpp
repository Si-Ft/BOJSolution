#include <stdio.h>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int dp[100001] = {0};
int breed[21];

int main() {
    int N,B;
    scanf("%d %d", &N, &B);
    rep(i,0,B) scanf("%d", breed+i);

    rep(i,1,100001) dp[i] = 1<<30;
    rep(i,0,B) {
        rep(j,breed[i],100001) {
            dp[j] = min(dp[j], dp[j-breed[i]] + 1);
        }
    }
    
    int beforeSound = 0;
    int ans = 0;
    rep(i,0,N) {
        int voice;
        scanf("%d", &voice);
        int fieldV = voice - beforeSound;
        if ((fieldV < 0) || (dp[fieldV] >= 1<<30)) {
            printf("-1");
            return 0;
        }
        ans += dp[fieldV];
        beforeSound = voice - 1;
        if (beforeSound<0) beforeSound = 0;
    }

    printf("%d", ans);

    return 0;
}