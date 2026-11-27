#include <stdio.h>
#include <queue>
#define rep(i,a,b) for(int i=a;i<b;i++)

struct Status {
    int y, x;   // 현재 위치
    int keys;   // 현재 가지고 있는 열쇠 상태 (a:0 ~ f:5 번째 비트마스크)
};

int N, M;               // 격자 크기
char grid[51][51];      // 필드 정보
int sy, sx;     // 시작점과 도착점 좌표

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool isKey(char c) {
    return c >= 'a' && c <= 'f';
}
bool isDoor(char c) {
    return c >= 'A' && c <= 'F';
}

int main() {
    scanf("%d %d", &N, &M);
    rep(i,0,N) rep(j,0,M) {
        scanf(" %c", &grid[i][j]);
        if (grid[i][j] == '0') { sy = i; sx = j; }
    }

    std::queue<Status> q;
    bool visited[51][51][64] = {false};
    q.push({sy, sx, 0});
    q.push({-1, -1, -1});   // dist 구간 구분용
    visited[sy][sx][0] = true;
    int dist = 0;

    while(!q.empty()) {
        Status c = q.front();
        q.pop();

        // 구간 경계 처리
        if (c.y == -1) {
            dist++;
            if (!q.empty()) q.push({-1, -1, -1});
            continue;
        }

        // 도착점 처리 (즉시 종료)
        if (grid[c.y][c.x] == '1') {
            printf("%d", dist);
            return 0;
        }

        rep(i,0,4) {
            Status n = {c.y + dy[i], c.x + dx[i], c.keys};
            
            if (n.y < 0 || n.y >= N || n.x < 0 || n.x >= M) continue;
            if (grid[n.y][n.x] == '#') continue;

            // 문인데 열쇠 없으면 벽처럼 처리
            if (isDoor(grid[n.y][n.x]) && !(c.keys & (1 << (grid[n.y][n.x] - 'A')))) continue;

            // 열쇠를 주웠으면 상태 갱신
            if (isKey(grid[n.y][n.x])) n.keys |= (1 << (grid[n.y][n.x] - 'a'));

            if (visited[n.y][n.x][n.keys]) continue;
            visited[n.y][n.x][n.keys] = true;
            q.push(n);
        }
    }

    // 결국 도착하지 못한 경우
    printf("-1");
    return 0;
}