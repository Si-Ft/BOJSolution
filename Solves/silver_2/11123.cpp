#include <stdio.h>
#include <queue>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

void PS(int TCnum);
void bfs(int sy, int sx);

int main() {
    int T;
    scanf("%d", &T);
    rep(i,1,T+1) PS(i);
    return 0;
}

int H,W,ans;
int grid[101][101];
void PS(int TCnum) {  
    ans = 0;  
    scanf("%d %d", &H, &W);
    rep(i,0,H) rep(j,0,W) scanf(" %c", &grid[i][j]);
    rep(i,0,H) rep(j,0,W) if (grid[i][j] == '#') bfs(i,j);
    printf("%d\n", ans);
}

void bfs(int sy, int sx) {
    queue<pair<int,int>> q;
    int dy[4] = {-1,1,0,0};
    int dx[4] = {0,0,-1,1};
    q.push({sy,sx});
    grid[sy][sx] = '.';
    ans++;

    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int y = p.first;
        int x = p.second;

        rep(dir,0,4) {
            int ny = y+dy[dir];
            int nx = x+dx[dir];
            if(ny<0 || nx<0 || ny>=H || nx>=W) continue;
            if(grid[ny][nx] == '.') continue;
            grid[ny][nx] = '.';
            q.push({ny,nx});
        }
    }
}