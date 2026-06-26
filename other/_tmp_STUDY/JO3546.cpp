#include <stdio.h>
#include <string.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

int H, W;
int cy, cx;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
char grid[16][16];
char seq[51];

int dirToNum(char dir);
bool isGameClear();
void printGrid();
int move(char dir);

int main() {
    scanf("%d %d", &H, &W);
    rep(i,0,H) {
        rep(j,0,W) {
            // 받는 입력 : . # + b B w W
            scanf(" %c", &grid[i][j]);
            if (grid[i][j] == 'w' || grid[i][j] == 'W') {
                cy = i;
                cx = j;
                if (grid[i][j] == 'w') grid[i][j] = '.';
                else grid[i][j] = '+';
            }
        }
    }

    scanf("%s", seq);
    rep(i,0,strlen(seq)) {
        if (move(seq[i])) {
            // 게임 클리어 시 종료
            return 0;
        }
    }
    printf("incomplete\n");
    printGrid();
    return 0;
}

int dirToNum(char dir) {
    if (dir == 'R') return 0;
    if (dir == 'D') return 1;
    if (dir == 'L') return 2;
    if (dir == 'U') return 3;
    return -1;
}

// 필드에 소문자 b가 남아있다면 게임 미클리어
bool isGameClear() {
    rep(i,0,H) rep(j,0,W) if (grid[i][j] == 'b') return false;
    return true;
}

// 단순 필드 상태 출력용
void printGrid() {
    rep(i,0,H) {
        rep(j,0,W) {
            // 플레이어 위치 별도로 표시
            if (i == cy && j == cx) {
                if (grid[i][j] == '+') printf("W");
                else printf("w");
            }
            else printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

int move(char dir) {
    int d = dirToNum(dir);
    int ny = cy + dy[d];
    int nx = cx + dx[d];

    // 벽이 있는 경우
    if (grid[ny][nx] == '#') return 0;

    // 앞이 Box인데 그 뒤에 또다른 Box나 벽이 있는 경우
    if (grid[ny][nx] == 'b' || grid[ny][nx] == 'B') {
        int nny = ny + dy[d];   // 상자의 뒷좌표
        int nnx = nx + dx[d];   // 상자의 뒷좌표
        if (grid[nny][nnx] == '#' || grid[nny][nnx] == 'b' || grid[nny][nnx] == 'B') return 0;

        // Box를 밀 수 있는 경우 (대소문자 분기 처리)

        // #1 대상 박스가 목표점 위에 있는지 여부
        if (grid[ny][nx] == 'b') grid[ny][nx] = '.';
        else if (grid[ny][nx] == 'B') grid[ny][nx] = '+';

        // #2 대상 박스를 밀어서 이동한 위치가 목표점 위인지 여부
        if (grid[nny][nnx] == '.') grid[nny][nnx] = 'b';
        else if (grid[nny][nnx] == '+') grid[nny][nnx] = 'B';
    }

    // 이동 가능한 경우
    cy = ny;
    cx = nx;

    if (isGameClear()) {
        printf("complete\n");
        printGrid();
        return 1;
    }

    return 0;
}