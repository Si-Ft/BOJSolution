#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

int ccw(int x1, int y1, int x2, int y2, int x3, int y3);

int x[5];
int y[5];

int main() {
    rep(i,1,5) scanf("%d %d", x+i, y+i);
    if (ccw(x[1], y[1], x[2], y[2], x[3], y[3]) 
    * ccw(x[1], y[1], x[2], y[2], x[4], y[4]) != -1) {
        printf("0");
        return 0;
    }
    if (ccw(x[3], y[3], x[4], y[4], x[1], y[1]) 
    * ccw(x[3], y[3], x[4], y[4], x[2], y[2]) != -1) {
        printf("0");
        return 0;
    }

    printf("1");
    return 0;
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
    long long res = 1LL*(x2-x1)*(y3-y1)-1LL*(y2-y1)*(x3-x1);
    if (res > 0) return 1;
    else if (res < 0) return -1;
    else return 0;
}