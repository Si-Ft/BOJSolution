#include <stdio.h>
#include <queue>
#define rep(i,a,b) for(int i=a;i<b;i++)

int N;
int rcut;
int grid[501][501];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

// 구역의 크기가 N*N의 75% 이상인 경우 true 반환 (소수점 버림 기준)
bool bfs(int curH) {
    bool visited[501][501] = {false};
    std::queue<std::pair<int,int>> q;

    // 모든 칸이 칠해질 때까지 각 구역의 최대 개수를 탐색
    rep(y,0,N) rep(x,0,N) {
        int area = 1; // 현재 구역의 크기
        if (visited[y][x]) continue;

        q.emplace(y,x);
        visited[y][x] = true;
        while (!q.empty()) {
            int cy = q.front().first;
            int cx = q.front().second;
            q.pop();
            int minBorder = grid[cy][cx] - curH;
            int maxBorder = grid[cy][cx] + curH;

            rep(d,0,4) {
                int ny = cy + dy[d];
                int nx = cx + dx[d];
                if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                if (visited[ny][nx]) continue;
                // H 조건에 의해 이동할 수 없는 곳인 경우
                if (grid[ny][nx] < minBorder || grid[ny][nx] > maxBorder) continue;
                q.emplace(ny, nx);
                visited[ny][nx] = true;
                area++;
            }
        }

        // 구역 크기 만족
        if (area >= rcut) return true;
    }

    // 모든 구역 살펴도 조건에 맞는 구역이 없는 경우
    return false;
}

int main() {
    scanf("%d", &N);
    rep(i,0,N) rep(j,0,N) scanf("%d", &grid[i][j]);
    rcut = (N * N * 3) / 4;

    // 이분 탐색을 통해 bfs 결과값이 true인 최소 H값 탐색
    int lo = 0, hi = 1000000;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (bfs(mid)) hi = mid;
        else lo = mid + 1;
    }
    printf("%d\n", lo);

    return 0;
}