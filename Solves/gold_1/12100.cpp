#include <stdio.h>
#include <string.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

int N;
int biggest = 0;
int board[20][20];

void simul2048(int prevBoard[20][20], int depth);
void moveBoard(int originBoard[20][20], int dir, int tmpBoard[20][20]);

int main() {
    scanf("%d", &N);
    rep(i,0,N) rep(j,0,N) scanf("%d", &board[i][j]);
    simul2048(board, 0);
    printf("%d", biggest);
    return 0;
}

void simul2048(int prevBoard[20][20], int depth) {    
    if (depth >= 5) {
        rep(i,0,N) rep(j,0,N) 
        if (biggest < prevBoard[i][j]) biggest = prevBoard[i][j];
        return;
    }

    rep(i,0,4) {
        int copied[20][20];
        int nxtBoard[20][20] = {0};
        memcpy(copied,prevBoard,sizeof(copied));
        moveBoard(copied, i, nxtBoard);
        simul2048(nxtBoard, depth+1);
    }
}

// dir | 0:상 | 1:하 | 2:좌 | 3:우
void moveBoard(int originBoard[20][20], int dir, int tmpBoard[20][20]) {
    // 상,하 일 경우, x축을 고정하고 y축으로 봄
    if (dir <= 1) {
        rep(x,0,N) {
            int st=0, step=1;
            if (dir%2 == 1) {
                st = N-1;
                step = -1;
            }
            bool merged = false;
            int lastAddr = st;
            for (int y=st; (y>=0) && (y<N); y+=step) {
                if (originBoard[y][x] == 0) continue;
                if (lastAddr == st || tmpBoard[lastAddr-step][x] != originBoard[y][x] || merged) {
                    tmpBoard[lastAddr][x] = originBoard[y][x];
                    if (step>0) lastAddr++;
                    else lastAddr--;
                    merged = false;
                }
                else {
                    // 합쳐야하는 경우
                    tmpBoard[lastAddr-step][x] *= 2;
                    merged = true;
                }
            }
        }
    }
    else {
        rep(x,0,N) {
            int st=0, step=1;
            if (dir%2 == 1) {
                st = N-1;
                step = -1;
            }
            bool merged = false;
            int lastAddr = st;
            for (int y=st; (y>=0) && (y<N); y+=step) {
                if (originBoard[x][y] == 0) continue;
                if (lastAddr == st || tmpBoard[x][lastAddr-step] != originBoard[x][y] || merged) {
                    tmpBoard[x][lastAddr] = originBoard[x][y];
                    if (step>0) lastAddr++;
                    else lastAddr--;
                    merged = false;
                }
                else {
                    // 합쳐야하는 경우
                    tmpBoard[x][lastAddr-step] *= 2;
                    merged = true;
                }
            }
        }
    }
}