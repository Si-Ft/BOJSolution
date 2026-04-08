#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

int main() {
    int N;
    scanf("%d", &N);
    int dots[51][2];

    int maxX = -1001, minX = 1001;
    int maxY = -1001, minY = 1001;
    rep(i,0,N) {
        int x,y;
        scanf("%d %d", &x, &y);
        dots[i][0] = x;
        dots[i][1] = y;
        if (maxX < x) maxX = x;
        if (minX > x) minX = x;
        if (maxY < y) maxY = y;
        if (minY > y) minY = y;
    }

    // 직사각형
    bool flatSquare = false;
    if (maxY-minY != maxX-minX) flatSquare = true;

    // 한군데라도 뚫려있으면 그부분 늘려서 정사각형으로 만들기 가능
    // case 1 : 딱 모서리의 점 : 좌우 아무데나 늘려도 타격없음 > 무시하고 다음
    // case 2 : 모서리가 아닌 변의 점 : 그 방향 변은 fix시킴 (이 변은 밀 수 없음)
    // case 3 : 애초에 변이 아닌 점 : 불가능, -1리턴
    bool lbrt[4] = {false}; // 왼쪽, 아래, 오른쪽, 위
    rep(i,0,N) {

        if ((dots[i][0] == minX || dots[i][0] == maxX) && 
        (dots[i][1] == minY || dots[i][1] == maxY)) continue;

        if (dots[i][0] == minX) lbrt[0] = true;
        else if (dots[i][1] == minY) lbrt[1] = true;
        else if (dots[i][0] == maxX) lbrt[2] = true;
        else if (dots[i][1] == maxY) lbrt[3] = true;
        else { printf("-1", i); return 0; }
    }

    if (flatSquare == false) { printf("%d", maxY-minY); return 0; }

    // 좌우가 긴 변일 경우
    if (maxY-minY < maxX-minX) {
        // 둘 다 밀 수 없을 경우
        if (lbrt[1] && lbrt[3]) printf("-1");
        else printf("%d", maxX-minX);
    }
    else {
        if (lbrt[0] && lbrt[2]) printf("-1");
        else printf("%d", maxY-minY);
    }
    return 0;
}