#include <stdio.h>
#include <vector>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

struct Line
{
    int sx;
    int sy;
    int ex;
    int ey;
} L;

int PS(int TCnum);
int isIntersection(Line L1, Line L2);
int ccw(int x1, int y1, int x2, int y2, int x3, int y3);

int main() {
    int T;
    scanf("%d", &T);
    rep(i,1,T+1) printf("%d\n", PS(i));

    return 0;
}

int PS(int TCnum) {
    Line tarLine, edgeT, edgeB, edgeL, edgeR; // 상하좌우 직사각형 변
    int xmin,ymin,xmax,ymax;
    int x1,y1,x2,y2;
    scanf("%d %d %d %d", &xmin,&ymin,&xmax,&ymax);
    scanf("%d %d %d %d", &x1,&y1,&x2,&y2);
    tarLine = {x1,y1,x2,y2};
    edgeT = {xmin,ymax,xmax,ymax};
    edgeB = {xmin,ymin,xmax,ymin};
    edgeL = {xmin,ymin,xmin,ymax};
    edgeR = {xmax,ymin,xmax,ymax};

    int ansTBLR[4];
    ansTBLR[0] = isIntersection(tarLine,edgeT);
    ansTBLR[1] = isIntersection(tarLine,edgeB);
    ansTBLR[2] = isIntersection(tarLine,edgeL);
    ansTBLR[3] = isIntersection(tarLine,edgeR);

    int ans = 0;
    rep(i,0,4) {
        ans += ansTBLR[i];
        if (ansTBLR[i] == 2) return 4;
    }

    int pX[4] = {xmin,xmax,xmin,xmax};
    int pY[4] = {ymax,ymax,ymin,ymin};

    // 0,2 0,3 1,2 1,3
    rep(i,0,4) {
        if ((ansTBLR[i/2] == 1) && (ansTBLR[2+(i%2)] == 1)) {
            if (ccw(x1,y1,x2,y2,pX[i],pY[i]) == 0) ans -= 1;
        }
    }

    return ans;
}


int isIntersection(Line L1, Line L2) {
    int P123 = ccw(L1.sx, L1.sy, L1.ex, L1.ey, L2.sx, L2.sy);
    int P124 = ccw(L1.sx, L1.sy, L1.ex, L1.ey, L2.ex, L2.ey);
    int P341 = ccw(L2.sx, L2.sy, L2.ex, L2.ey, L1.sx, L1.sy);
    int P342 = ccw(L2.sx, L2.sy, L2.ex, L2.ey, L1.ex, L1.ey);

    // 네 점이 일직선상. 한점만 겹치면 1, 범위가 겹치면 2
    if (!(P123 || P124 || P341 || P342)) {
        if (L1.sx != L1.ex) {
            int maxL1x = max(L1.sx, L1.ex);
            int minL1x = min(L1.sx, L1.ex);
            int maxL2x = max(L2.sx, L2.ex);
            int minL2x = min(L2.sx, L2.ex);
            
            int overlapStart = max(minL1x, minL2x);
            int overlapEnd = min(maxL1x, maxL2x);
            
            if (overlapStart == overlapEnd) return 1;
            else if (overlapStart < overlapEnd) return 2;
        }
        else {
            int maxL1y = max(L1.sy, L1.ey);
            int minL1y = min(L1.sy, L1.ey);
            int maxL2y = max(L2.sy, L2.ey);
            int minL2y = min(L2.sy, L2.ey);
            
            int overlapStart = max(minL1y, minL2y);
            int overlapEnd = min(maxL1y, maxL2y);
            
            if (overlapStart == overlapEnd) return 1;
            else if (overlapStart < overlapEnd) return 2;
        }
        return 0;
    }

    if ((P123 * P124 <= 0) && (P341 * P342 <= 0)) return 1;
    else return 0;
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
    long long res = 1LL*(x2-x1)*(y3-y1)-1LL*(y2-y1)*(x3-x1);
    if (res > 0) return 1;
    else if (res < 0) return -1;
    else return 0;
}