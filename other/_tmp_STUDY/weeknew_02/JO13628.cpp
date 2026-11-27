#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

int main() {
    int el[3], H;     // 에스컬레이터의 길이 셋, 체력
    int btime = 601;
    scanf("%d %d %d", &el[0], &el[1], &el[2]);
    scanf("%d", &H);
    // 모든 경우의 수 탐색 (bitmask)
    rep(i,0,8) {
        int curTime = 0;
        int leftH = H;

        // 각 에스컬레이터를 걸어갈지 가만히 있을지 결정
        rep(bit,0,3) {
            if (i & (1 << bit)) {
                curTime += el[bit] / 2;
                leftH -= el[bit] / 2;
            } else {
                curTime += el[bit];
            }
        }

        // 체력이 남아있으면 최소 시간 갱신
        if (leftH > 0) btime = btime < curTime ? btime : curTime;
    }

    printf("%d\n", btime);
    return 0;
}