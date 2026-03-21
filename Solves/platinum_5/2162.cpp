#include <stdio.h>
#include <vector>
#include <queue>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

struct Line
{
    int sx;
    int sy;
    int ex;
    int ey;
} L;

vector<Line> lines; // 선분 저장소
vector<vector<int>> conn(3001); // 이어진 선분 번호 (0부터)
int N; // 선분의 개수 겸 그래프 계산 시 노드의 개수
bool visited[3001] = {false};

bool isIntersection(Line L1, Line L2);
int ccw(int x1, int y1, int x2, int y2, int x3, int y3);
int sizeOfGraph(int start);

int main() {
    scanf("%d", &N);
    rep(i,0,N) {
        scanf("%d %d %d %d", &L.sx, &L.sy, &L.ex, &L.ey);
        lines.push_back(L);

        rep(j,0,i) {
            if (isIntersection(lines[i], lines[j])) {
                conn[i].push_back(j);
                conn[j].push_back(i);
            }
        }
    }

    // 그래프 순회해서 가장 큰 그래프랑, 독립된 그래프 개수 출력
    int maxSize=0;
    int graphCount=0;
    rep(i,0,N) {
        if (visited[i]) continue;
        graphCount++;
        maxSize = max(sizeOfGraph(i), maxSize);
    }
    printf("%d\n%d", graphCount, maxSize);

    return 0;
}

int sizeOfGraph(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int size = 0;

    while (!q.empty()) {
        int curNode = q.front();
        q.pop();
        size++;

        for (int next : conn[curNode]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    return size;
}

bool isIntersection(Line L1, Line L2) {
    int P123 = ccw(L1.sx, L1.sy, L1.ex, L1.ey, L2.sx, L2.sy);
    int P124 = ccw(L1.sx, L1.sy, L1.ex, L1.ey, L2.ex, L2.ey);
    int P341 = ccw(L2.sx, L2.sy, L2.ex, L2.ey, L1.sx, L1.sy);
    int P342 = ccw(L2.sx, L2.sy, L2.ex, L2.ey, L1.ex, L1.ey);

    if (!(P123 || P124 || P341 || P342)) {
        if (L1.sx != L1.ex) {
            if ((max(L1.sx, L1.ex) >= min(L2.sx, L2.ex)) && 
            (max(L2.sx, L2.ex) >= min(L1.sx, L1.ex))) {
                return true;
            }
        }
        else {
            if ((max(L1.sy, L1.ey) >= min(L2.sy, L2.ey)) && 
            (max(L2.sy, L2.ey) >= min(L1.sy, L1.ey))) {
                return true;
            }
        }
        return false;
    }

    if ((P123 * P124 <= 0) && (P341 * P342 <= 0)) return true;
    else return false;
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
    long long res = 1LL*(x2-x1)*(y3-y1)-1LL*(y2-y1)*(x3-x1);
    if (res > 0) return 1;
    else if (res < 0) return -1;
    else return 0;
}