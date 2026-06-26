#include <stdio.h>
#include <vector>
#include <queue>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int N,M;            // 세로, 가로
int field[8][8];    // 0: 빈칸, 1: 벽, 2: 바이러스
vector<int> emptySpaces; // 빈칸의 인덱스 저장
vector<int> virusPositions; // 바이러스의 인덱스 저장

int bfs();
int main() {
    scanf("%d %d", &N, &M);
    rep(i,0,N) {
        rep(j,0,M) {
            scanf("%d", &field[i][j]);
            // 빈칸과 바이러스 정보 1차원으로 저장
            if (field[i][j] == 0) emptySpaces.push_back(i*M + j);
            if (field[i][j] == 2) virusPositions.push_back(i*M + j);
        }
    }

    // 3개의 벽을 세우고, bfs로 바이러스 확산
    int ans = 0;
    int ec = emptySpaces.size();
    rep(i,0,ec) {
        field[emptySpaces[i]/M][emptySpaces[i]%M] = 1;
        rep(j,i+1,ec) {
            field[emptySpaces[j]/M][emptySpaces[j]%M] = 1;
            rep(k,j+1,ec) {
                field[emptySpaces[k]/M][emptySpaces[k]%M] = 1;
                ans = max(ans, bfs());  // 벽 세운 후, 안전영역 개수 갱신
                field[emptySpaces[k]/M][emptySpaces[k]%M] = 0;
            }
            field[emptySpaces[j]/M][emptySpaces[j]%M] = 0;
        }
        field[emptySpaces[i]/M][emptySpaces[i]%M] = 0;
    }
    printf("%d\n", ans);
    return 0;
}

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

// 바이러스 확산
int bfs() {
    queue<int> q;   // 탐색할 위치
    int tempField[8][8];
    rep(i,0,N) rep(j,0,M) tempField[i][j] = field[i][j];

    for (int pos : virusPositions) q.push(pos);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        int x = cur / M;
        int y = cur % M;

        // 4방향 탐색
        rep(d,0,4) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue; // 범위 벗어남
            if (tempField[nx][ny] != 0) continue; // 벽이거나 이미 바이러스가 퍼진 곳

            tempField[nx][ny] = 2; // 바이러스 확산
            q.push(nx*M + ny);
        }
    }
    // 안전 영역의 개수
    int safeCount = 0;
    rep(i,0,N) rep(j,0,M) if (tempField[i][j] == 0) safeCount++;
    return safeCount;
}