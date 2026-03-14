#include <stdio.h>
#include <queue>
#include <tuple>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int N,M,H;
int grid[101][101][101];
int dist[101][101][101] = {0};

int dx[6] = {0,0,-1,1,0,0};
int dy[6] = {-1,1,0,0,0,0};
int dz[6] = {0,0,0,0,-1,1};

queue<tuple<int,int,int>> q;

int main() {
    scanf("%d %d %d", &M, &N, &H);
    rep(k,0,H) {
        rep(i,0,N) {
            rep(j,0,M) {
                scanf("%d", &grid[i][j][k]);
                if (grid[i][j][k] == 1) {
                    q.emplace(i,j,k);
                    dist[i][j][k] = 1;
                }
            }
        }
    }
    
    while(!q.empty()){
        tuple<int,int,int> p = q.front();
        int x = get<0>(p);
        int y = get<1>(p);
        int z = get<2>(p);
        q.pop();

        for(int dir=0; dir<6; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];

            if(ny<0 || nx<0 || nz<0 || nx>=N || ny>=M || nz>=H) continue;
            if(grid[nx][ny][nz] == -1) continue;
            if(dist[nx][ny][nz] != 0) continue;

            dist[nx][ny][nz] = dist[x][y][z] + 1;
            q.emplace(nx,ny,nz);
        }
    }

    int mx=1;
    rep(k,0,H) {
        rep(i,0,N) {
            rep(j,0,M) {
                if (grid[i][j][k] == 0 && dist[i][j][k] == 0) {
                    printf("-1");
                    return 0;
                }
                if (grid[i][j][k] != 0) continue;
                mx = max(mx, dist[i][j][k]);
            }
        }
    }

    printf("%d", mx-1);
    return 0;
}