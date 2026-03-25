#include <stdio.h>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int euclidDist(int A[2], int B[2]) {
    int xDist = abs(A[0] - B[0]);
    int yDist = abs(A[1] - B[1]);
    return xDist * xDist + yDist * yDist;
}

int main() {
    int N;
    int dot[1001][2];
    scanf("%d", &N);
    rep(i,0,N) scanf("%d %d", &dot[i][0], &dot[i][1]);

    int minDistDot = -1;
    int minDist = __INT_MAX__;
    rep(i,0,N) {
        int maxD = -1;
        rep(j,0,N) maxD = max(maxD, euclidDist(dot[i], dot[j]));
        if (minDist > maxD){
            minDistDot = i;
            minDist = maxD;
        }
    }

    printf("%d %d", dot[minDistDot][0], dot[minDistDot][1]);

    return 0;
}