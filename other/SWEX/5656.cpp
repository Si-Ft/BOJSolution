#include <stdio.h>
#include <string.h>
#include <queue>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void PS(int TCnum);
void breakBlock(int grid[15][12], int depth);
void breakSimul(int grid[15][12], int x);
void orderSimul(int grid[15][12]);

int main() {
    int T;
    scanf("%d", &T);
    rep(i,1,T+1) PS(i);
    
    return 0;
}

int N,W,H;
int ans;
void PS(int TCnum) {
    ans = 999;
    scanf("%d %d %d", &N, &W, &H);
    int grid[15][12];
    rep(i,0,H) rep(j,0,W) scanf("%d", &grid[i][j]);

    breakBlock(grid, 0);
    printf("#%d %d\n", TCnum, ans);
}

void breakBlock(int grid[15][12], int depth) {
    if (depth == N) {
        int cnt = 0;
        rep(i,0,H) rep(j,0,W) if (grid[i][j] > 0) cnt++;
        ans = (ans<cnt)?ans:cnt;
        return;
    }

    rep(i,0,W) {
        int newGrid[15][12];
        memcpy(newGrid, grid, sizeof(newGrid));
        breakSimul(newGrid, i);
        orderSimul(newGrid);
        breakBlock(newGrid, depth+1);
    }
}

// 특정 X방향에 구슬을 떨궈서 블록 파괴하는 시뮬레이션
void breakSimul(int grid[15][12], int x) {
    int y = 0;
    while (y < H && grid[y][x] == 0) y++;
    if (y == H) return;

    queue<pair<int,int>> q;
    q.push({y,x});

    while(!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        int range = grid[cy][cx];
        grid[cy][cx] = 0;
        for (int d = 1; d < range; d++) {
            if (cy-d >= 0 && grid[cy-d][cx] > 0) q.push({cy-d, cx});    // 위방향
            if (cy+d < H && grid[cy+d][cx] > 0) q.push({cy+d, cx});     // 아랫방향
            if (cx-d >= 0 && grid[cy][cx-d] > 0) q.push({cy, cx-d});    // 왼쪽방향
            if (cx+d < W && grid[cy][cx+d] > 0) q.push({cy, cx+d});     // 오른쪽방향
        }
    }
}

// 폭파 후, 블록을 내리는 시뮬레이션
void orderSimul(int grid[15][12]) {
    for (int x = 0; x < W; x++) {
        int emptyRow = H - 1;
        for (int y = H - 1; y >= 0; y--) {
            if (grid[y][x] > 0) {
                if (y != emptyRow) {
                    grid[emptyRow][x] = grid[y][x];
                    grid[y][x] = 0;
                }
                emptyRow--;
            }
        }
    }
}