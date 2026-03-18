#include <stdio.h>

// P1, P2를 기준으로 P3의 방향이 반시계면 1, 시계면 -1, 직선이면 0
int ccw(int x1, int y1, int x2, int y2, int x3, int y3);

int main() {
    int P1x, P1y, P2x, P2y, P3x, P3y;
    scanf("%d %d %d %d %d %d", &P1x, &P1y, &P2x, &P2y, &P3x, &P3y);
    printf("%d", ccw(P1x, P1y, P2x, P2y, P3x, P3y));
    return 0;
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
    long long res = 1LL*(x2-x1)*(y3-y1)-1LL*(y2-y1)*(x3-x1);
    if (res > 0) return 1;
    else if (res < 0) return -1;
    else return 0;
}