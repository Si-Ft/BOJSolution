#include <stdio.h>
#include <queue>
using namespace std;

int N,M;
int grid[1001][1001];
int dist[1001][1001];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void bfs(int sx, int sy);

int main() {

    int startX, startY;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            scanf("%d", &grid[i][j]);
            if (grid[i][j] == 2) {
                startX = i;
                startY = j;
            }
        }
    }
    
    bfs(startX, startY);
    dist[startX][startY]=0;

    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            if (dist[i][j] != 0) {
                printf("%d ", dist[i][j]);
                continue;
            }

            if (grid[i][j] == 2 || grid[i][j] == 0) printf("0 ");
            else printf("-1 ");
        }
        printf("\n");
    }
    
    return 0;
}

void bfs(int sx, int sy){
    queue<pair<int,int>> q;
    q.push({sx,sy});
    dist[sx][sy] = 0; // 시작거리

    while(!q.empty()){
        pair<int,int> p = q.front();
        int x = p.first;
        int y = p.second;
        q.pop();

        for(int dir=0; dir<4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(ny<0 || nx<0 || nx>=N || ny>=M) continue;
            if(grid[nx][ny] == 0) continue;
            if(dist[nx][ny] != 0) continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx,ny});
        }
    }
}