#include <stdio.h>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int dp[501][501]; // [st번째 행렬부터][en번째 행렬까지]최소 연산 수
    int proc[501][2]; // [행렬번호][0:r|1:c]
    rep(i,0,N) scanf("%d %d", &proc[i][0], &proc[i][1]);

    // st부터 en까지 최선의 연산을 찾는다/
    int st=-1, en=-1;
    while(1) {
        // 이중 루프 수동 구현 (들여쓰기 올라가는 거 싫음)
        st++;
        en++;
        if (en >= N) {
            en-=(st-1);
            st=0;
        }
        if (st==en) {
            dp[st][en] = 0;
            continue;
        }

        // i값을 기준으로 행렬의 두 부분을 나누고, 마지막에 곱한 값이 가장 작은 경우를 찾기

        int minCal=__INT_MAX__;
        rep(i,st,en) {
            int mergeCost = proc[st][0] * proc[i][1] * proc[en][1];
            minCal = min(dp[st][i] + dp[i+1][en] + mergeCost, minCal);
        }
        dp[st][en] = minCal;
        if (st==0 && en==(N-1)) break;
    }

    printf("%d", dp[0][N-1]);
    return 0;
}