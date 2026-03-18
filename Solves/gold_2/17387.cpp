#include <stdio.h>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3);

int x[5];
int y[5];

int main() {
    rep(i,1,5) scanf("%d %d", x+i, y+i);

    int P123 = ccw(x[1], y[1], x[2], y[2], x[3], y[3]);
    int P124 = ccw(x[1], y[1], x[2], y[2], x[4], y[4]);
    int P341 = ccw(x[3], y[3], x[4], y[4], x[1], y[1]);
    int P342 = ccw(x[3], y[3], x[4], y[4], x[2], y[2]);

    // 모든 점이 일직선 상에 있을 경우
    if (!(P123 || P124 || P341 || P342)) {
        if (x[1] != x[2]) {
            if ((max(x[1], x[2]) >= min(x[3], x[4])) && 
            (max(x[3], x[4]) >= min(x[1], x[2]))) {
                printf("1");
                return 0;
            }
        }
        else {
            if ((max(y[1], y[2]) >= min(y[3], y[4])) && 
            (max(y[3], y[4]) >= min(y[1], y[2]))) {
                printf("1");
                return 0;
            }
        }
        printf("0");
        return 0;
    }

    if ((P123 * P124 <= 0) && (P341 * P342 <= 0)) printf("1");
    else printf("0");

    return 0;
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
    long long res = 1LL*(x2-x1)*(y3-y1)-1LL*(y2-y1)*(x3-x1);
    if (res > 0) return 1;
    else if (res < 0) return -1;
    else return 0;
}