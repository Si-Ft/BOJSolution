#include <stdio.h>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)

int arr[1000001];
int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    rep(i,0,N) scanf("%d", &arr[i]);

    int ans = N+1;          // 가장 작은 구간 길이
    int lioncnt = 0;        // 현재까지의 라이언 인형 수
    int st = 0, en = -1;    // 시작 끝 포인터
    while(true) {
        // printf("%d %d %d\n", st, en, lioncnt);
        if (lioncnt < K) {
            en++;
            if (en >= N) break;
            if (arr[en] == 1) lioncnt++;
        }
        else {
            if (arr[st] == 1) lioncnt--;
            st++;
        }
        if (lioncnt >= K) ans = std::min(ans, en-st+1);
    }
    if (ans == N+1) ans = -1;
    printf("%d\n", ans);
    return 0;
}