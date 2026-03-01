#include <iostream>
#include <queue>
using namespace std;

int N, M;
int grid[1001][1001];
int dist[1001][1001];

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void bfs(int sy, int sx){
    queue<pair<int,int>> q;
    q.push({sy,sx});
    dist[sy][sx] = 1; // 시작거리

    while(!q.empty()){
        pair<int,int> p = q.front();
        int y = p.first;
        int x = p.second;
        q.pop();

        for(int dir=0; dir<4; dir++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            // 범위 체크
            if(ny<0 || nx<0 || ny>=N || nx>=M) continue;

            // 이동 불가
            if(grid[ny][nx] == 0) continue;

            // 방문 체크
            if(dist[ny][nx] != 0) continue;

            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny,nx});
        }
    }
}