// 8676. 동현이와 한결이는 아이돌 D4

#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define dv 1000000007

void PS(int TCnum);

int main() {
    int T;
    scanf("%d", &T);
    rep(i,1,T+1) PS(i);
    
    return 0;
}

void PS(int TCnum) {
    // 0123456
    // SAMSUNG
    int dp[7] = {0};
    char S[10001];
    scanf("%s", S);

    for (int i=0; S[i]; i++) {
        // 이전 경우의 수 전이
        switch(S[i]) {
            case 'S':
                dp[0]++;
                dp[3] = (dp[3] + dp[2]) % dv;
                break;
            case 'A':
                dp[1] = (dp[1] + dp[0]) % dv;
                break;
            case 'M':
                dp[2] = (dp[2] + dp[1]) % dv;
                break;
            case 'U':
                dp[4] = (dp[4] + dp[3]) % dv;
                break;
            case 'N':
                dp[5] = (dp[5] + dp[4]) % dv;
                break;
            case 'G':
                dp[6] = (dp[6] + dp[5]) % dv;
                break;
        }
    }
    printf("#%d %d\n", TCnum, dp[6]);
}