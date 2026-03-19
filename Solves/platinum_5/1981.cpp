#include <stdio.h>
#include <queue>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

int N;
int grid[101][101];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int bfs(int sx, int sy, int L, int R);

int main() {
    scanf("%d", &N);
    int maxNum = -1;
    int minNum = 201;

    rep(i,0,N) {
        rep(j,0,N) {
            scanf("%d", &grid[i][j]);
            maxNum = max(maxNum, grid[i][j]);
            minNum = min(minNum, grid[i][j]);
        }
    }

    int lowest = 0;
    int highest = maxNum - minNum;
    int ans;

    while (lowest <= highest) {
        int D = (lowest + highest) / 2;
        bool isBfsPossible = false;
        
        int startL = 0;
        while (1) {
            if (grid[0][0] < startL) break;
            if (grid[0][0] > startL+D) {
                startL++;
                continue;
            }
            
            int res = bfs(0,0,startL,startL+D);
            if (res != 0) {
                isBfsPossible = true;
                break;
            }
            startL++;
        }

        if (isBfsPossible) {
            ans = D;
            highest = D - 1;
        }
        else {
            lowest = D + 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}

int bfs(int sx, int sy, int L, int R) {
    int dist[101][101] = {0};
    queue<pair<int,int>> q;
    q.push({sx,sy});
    dist[sx][sy] = 1; // 시작거리

    while(!q.empty()){
        pair<int,int> p = q.front();
        int x = p.first;
        int y = p.second;
        q.pop();

        for(int dir=0; dir<4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(ny<0 || nx<0 || nx>=N || ny>=N) continue;
            if(grid[nx][ny] < L || grid[nx][ny] > R) continue;
            if(dist[nx][ny] != 0) continue;
            

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx,ny});
        }
    }

    return dist[N-1][N-1];
}