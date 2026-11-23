#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int N;
int map[100][100];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int bfs(int y, int x, int inum) {
    bool visited[100][100] = {false};

    // 현재 속해 있는 섬의 좌표들을 전부 체크
    queue<int> q;   // 100*y + x
    vector<int> iaxis;
    q.push(100*y + x);
    map[y][x] = inum;
    visited[y][x] = true;
    iaxis.push_back(100*y + x);

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        int cy = cur / 100;
        int cx = cur % 100;

        rep(dir,0,4) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if(visited[ny][nx]) continue;
            if(map[ny][nx] != 1) continue;
            map[ny][nx] = inum;
            visited[ny][nx] = true;
            iaxis.push_back(100*ny + nx);
            q.push(100*ny + nx);
        }
    }

    // 현재 섬 좌표를 기준으로 가장 가까운 섬 까지의 거리를 bfs로 탐색
    int curDist = 0;
    for (int ax : iaxis) q.push(ax);
    q.push(-1);  // 레벨 구분용으로 -1을 넣어줌
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        // printf("%d ", cur);
        if(cur == -1) {
            curDist++;
            if(!q.empty()) q.push(-1);
            continue;
        }
        int cy = cur / 100;
        int cx = cur % 100;

        rep(dir,0,4) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if(visited[ny][nx]) continue;       // 본인 위치 섬은 여기서 걸러짐
            if(map[ny][nx] != 0) return curDist;

            visited[ny][nx] = true;
            q.push(100*ny + nx);
        }
    }
    return 999;
}

int main() {
    scanf("%d", &N);
    rep(i,0,N) rep(j,0,N) scanf("%d", &map[i][j]);
    int ans = 1<<9;
    int inum = 2;

    rep(i,0,N) rep(j,0,N) {
        if(map[i][j] == 1) {
            ans = min(ans, bfs(i, j, inum));
            inum++;
        }
    }

    printf("%d\n", ans);
    return 0;
}