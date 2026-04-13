#include <stdio.h>
#include <iostream>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3);
int isIntersect();

int x[5];
int y[5];

int main() {
    rep(i,1,5) scanf("%d %d", x+i, y+i);

    int ans = isIntersect();
    if (ans <= 1) {
        printf("%d", ans);
        return 0;
    }
    // 이미 isIntersect에서 처리
    if (ans == 3) return 0;

    // 두 직선의 교점을 찾는다
    printf("1\n");

    long long bunmo = 1LL*(x[1]-x[2])*(y[3]-y[4]);
    bunmo -= 1LL*(y[1]-y[2])*(x[3]-x[4]);

    long long sect12 = 1LL*x[1]*y[2] - 1LL*y[1]*x[2];
    long long sect34 = 1LL*x[3]*y[4] - 1LL*y[3]*x[4];

    long long bunjapx = sect12*(x[3]-x[4]) - sect34*(x[1]-x[2]);
    long long bunjapy = sect12*(y[3]-y[4]) - sect34*(y[1]-y[2]);

    long double px = (long double)bunjapx / bunmo;
    long double py = (long double)bunjapy / bunmo;
    printf("%.10lf %.10lf", (double)px, (double)py);

}

int isIntersect() {
    int P123 = ccw(x[1], y[1], x[2], y[2], x[3], y[3]);
    int P124 = ccw(x[1], y[1], x[2], y[2], x[4], y[4]);
    int P341 = ccw(x[3], y[3], x[4], y[4], x[1], y[1]);
    int P342 = ccw(x[3], y[3], x[4], y[4], x[2], y[2]);

    // 모든 점이 일직선 상에 있을 경우
    if (!(P123 || P124 || P341 || P342)) {
        // 두 선이 완전히 겹칠 때
        if ((x[1] == x[3] && y[1] == y[3] && x[2] == x[4] && y[2] == y[4]) ||
            (x[1] == x[4] && y[1] == y[4] && x[2] == x[3] && y[2] == y[3])) {
            return 1;
        }
        if (x[1] != x[2]) {
            int minX = max(min(x[1], x[2]), min(x[3], x[4]));
            int maxX = min(max(x[1], x[2]), max(x[3], x[4]));
            if (minX < maxX) {
                return 1;
            } else if (minX == maxX) {
                if ((x[1] == x[3]) || (x[1] == x[4]))
                    printf("1\n%d %d", x[1], y[1]);
                else
                    printf("1\n%d %d", x[2], y[2]);
                return 3;
            }
        }
        else {
            int minY = max(min(y[1], y[2]), min(y[3], y[4]));
            int maxY = min(max(y[1], y[2]), max(y[3], y[4]));
            if (minY < maxY) {
                return 1;
            } else if (minY == maxY) {
                if ((y[1] == y[3]) || (y[1] == y[4]))
                    printf("1\n%d %d", x[1], y[1]);
                else
                    printf("1\n%d %d", x[2], y[2]);
                return 3;
            }
        }
        return 0;
    }

    if ((P123 * P124 <= 0) && (P341 * P342 <= 0)) return 2;
    else return 0;
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
    long long res = 1LL*(x2-x1)*(y3-y1)-1LL*(y2-y1)*(x3-x1);
    if (res > 0) return 1;
    else if (res < 0) return -1;
    else return 0;
}