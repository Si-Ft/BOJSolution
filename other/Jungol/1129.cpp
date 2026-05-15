#include <stdio.h>
#include <vector>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

struct Line {
    int x1, y1, x2, y2;
};
vector<Line> lines;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3);
int isIntersect(Line l1, Line l2);

int main() {
    int N;
    scanf("%d", &N);
    rep(i,0,N) {
        Line l;
        scanf("%d %d %d %d", &l.x1, &l.y1, &l.x2, &l.y2);
        lines.push_back(l);
    }

    int ans = 0;
    rep(i,0,N) {
        rep(j,i+1,N) {
            if (isIntersect(lines[i], lines[j])) {
                ans++;
            }
        }
    }

    printf("%d", ans);
    return 0;
}

int isIntersect(Line l1, Line l2) {
    int P123 = ccw(l1.x1, l1.y1, l1.x2, l1.y2, l2.x1, l2.y1);
    int P124 = ccw(l1.x1, l1.y1, l1.x2, l1.y2, l2.x2, l2.y2);
    int P341 = ccw(l2.x1, l2.y1, l2.x2, l2.y2, l1.x1, l1.y1);
    int P342 = ccw(l2.x1, l2.y1, l2.x2, l2.y2, l1.x2, l1.y2);

    // 교차하면 1 리턴 (완전히 교차되는 경우만 포함)
    if ((P123 * P124 < 0) && (P341 * P342 < 0)) return 1;
    else return 0;
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
    long long res = 1LL*(x2-x1)*(y3-y1)-1LL*(y2-y1)*(x3-x1);
    if (res > 0) return 1;
    else if (res < 0) return -1;
    else return 0;
}