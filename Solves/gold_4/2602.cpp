#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

int main() {
    // 입력
    int duruLen = 0;            // 두루마리 문자열 길이
    char duru[21];              // 두루마리에 적힌 문자열
    int bridgeLen = 0;          // 다리 문자열 길이
    char bridge[2][101];        // 다리의 문자열 (0: 위쪽, 1: 아래쪽)

    scanf(" %s", duru);
    scanf(" %s", bridge[0]);
    scanf(" %s", bridge[1]);
    while(bridge[0][bridgeLen] != '\0') bridgeLen++;
    while(duru[duruLen] != '\0') duruLen++;

    // idx : dp[다리상하][다리위치][두루마리idx]
    int dp[2][101][21] = {0};
    rep(i,0,bridgeLen) {
        rep(j,0,2) {
            // 첫글자인 경우 새로운 경우의 수 생성
            if(bridge[j][i] == duru[0]) dp[j][i][0] = 1;

            // 이전 글자에서 이어질 수 있는 경우 현재 위치에 경우의 수 추가
            rep(p,0,i) {    // 이전 다리 위치 전체 인덱스 확인
                rep(l,1,duruLen) {    // 모든 글자에 대해서 이어지는 경우 확인
                    if(bridge[j][i] == duru[l]) dp[j][i][l] += dp[1-j][p][l-1];
                }
            }
        }
    }

    int result = 0;
    rep(i,0,bridgeLen) {
        result += dp[0][i][duruLen-1] + dp[1][i][duruLen-1];
    }
    printf("%d\n", result);

    return 0;
}