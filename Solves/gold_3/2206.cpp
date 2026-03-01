#include <stdio.h>
#include <queue>
#include <tuple>
using namespace std;

int grid[1001][1001];
int dist[1001][1001][2];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void bfs(int startX, int startY);
int N,M;

int main() {
    scanf("%d %d", &N,&M);

    // input 받기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            scanf(" %c", &c);
            if (c=='0') grid[i][j]=0;
            else grid[i][j]=1;
        }
    }
    bfs(0,0); // 이거 돌리면 끝점까지 dist에 저장됨.

    int ans1 = dist[N-1][M-1][0];
    int ans2 = dist[N-1][M-1][1];
    if (ans1 + ans2 == 0) printf("-1");
    else if (ans1 == 0) printf("%d", ans2);
    else if (ans2 == 0) printf("%d", ans1);
    else printf("%d", min(ans1, ans2));

    return 0;
}

void bfs(int startX, int startY) {
    queue<tuple<int,int,int>> q; // x, y, 벽뚫여부 노드 순회 저장하는 곳
    q.emplace(startX, startY, 0); // 초기 세팅
    dist[startX][startY][0] = 1; // 처음 정점 거리는 1

    while(!q.empty()) {
        // 순회할 현재 정점 정보 빼내기
        tuple<int,int,int> tp = q.front();
        int x = get<0>(tp);
        int y = get<1>(tp);
        int bw = get<2>(tp);
        q.pop();
        //printf("%d %d %d %d\n", x, y, bw, dist[x][y][bw]);

        for (int i=0;i<4;i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];

            // 예외 체크 (범위 밖)
            if (ny<0 || nx<0 || nx>=N || ny>=M) continue;
            // 예외 체크 (이미 방문함)
            if (dist[nx][ny][bw] != 0) continue;

            // 막힌 벽이 있을때, 뚫을 수 있는 횟수가 없다면 패스
            if ((grid[nx][ny] == 1) && (bw==1)) continue;

            // 벽이 있을 경우, 벽뚫 체크가 된 라벨을 붙이고 노드를 위로 올림.
            if (grid[nx][ny] == 1) {
                dist[nx][ny][1] = dist[x][y][0]+1; 
                q.emplace(nx,ny,1);
            }
            // 벽이 없는 경우, 현재 bw상태를 가지고 
            else {
                dist[nx][ny][bw] = dist[x][y][bw]+1;
                q.emplace(nx,ny,bw);
            }
        }
    }
}