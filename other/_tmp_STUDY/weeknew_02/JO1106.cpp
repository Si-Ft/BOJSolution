#include <stdio.h>
#include <queue>
#define rep(i,a,b) for(int i=a;i<b;i++)

int dist[101][101] = {0};
// 말 이동경로 1시 방향부터 시계방향
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int sy, sx, ey, ex;     // 범위 0부터가 아닌 1~100임에 유의
    scanf("%d %d %d %d", &sy, &sx, &ey, &ex);

    std::queue<std::pair<int,int>> q;
    q.emplace(sy, sx);
    dist[sy][sx] = 1;
    while(!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        if (cy == ey && cx == ex) {
            printf("%d\n", dist[cy][cx] - 1);
            break;
        }

        rep(i,0,8) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 1 || ny > N || nx < 1 || nx > M) continue;
            if (dist[ny][nx] != 0) continue;
            dist[ny][nx] = dist[cy][cx] + 1;
            q.emplace(ny, nx);
        }
    }

    return 0;
}