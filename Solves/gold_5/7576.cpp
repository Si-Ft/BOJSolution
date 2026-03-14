#include <stdio.h>
#include <queue>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int N,M;
int grid[1001][1001];
int dist[1001][1001] = {0};

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

queue<pair<int,int>> q;

int main() {
    scanf("%d %d", &M, &N);
    rep(i,0,N) {
        rep(j,0,M) {
            scanf("%d", &grid[i][j]);
            if (grid[i][j] == 1) {
                q.push({i,j});
                dist[i][j] = 1;
            }
        }
    }
    
    while(!q.empty()){
        pair<int,int> p = q.front();
        int x = p.first;
        int y = p.second;
        q.pop();

        for(int dir=0; dir<4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(ny<0 || nx<0 || nx>=N || ny>=M) continue;
            if(grid[nx][ny] == -1) continue;
            if(dist[nx][ny] != 0) continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx,ny});
        }
    }

    int mx=1;
    rep(i,0,N) {
        rep(j,0,M) {
            if (grid[i][j] == 0 && dist[i][j] == 0) {
                printf("-1");
                return 0;
            }
            if (grid[i][j] != 0) continue;
            mx = max(mx, dist[i][j]);
        }
    }

    printf("%d", mx-1);
    return 0;
}