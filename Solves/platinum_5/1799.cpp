#include <stdio.h>
#include <stack>
#include <algorithm>
using namespace std;

int N;
int chess[10][10];
int curCh1=0, maxCh1=0, curCh2=0, maxCh2=0;
// 수 변환 - 비활성화된 칸 : 0 | 놓을 수 없는 칸 : 0 > 1 | 놓을 수 있는 칸 : 1 > 2
int ch1[10][10] = {0}; // 검정 바닥 비숍만 갈 수 있는 판
int ch2[10][10] = {0}; // 하얀 바닥 비숍만 갈 수 있는 판
stack<pair<int,int>> erasedBlock; // <-1, -1> = 백트래킹 시작 체크

void backtrackChess(int x, int y, int panNum);

int main() {
    scanf("%d", &N);
    for (int i=0;i<N;i++) for (int j=0;j<N;j++) scanf("%d", &chess[i][j]);

    // 체스판 분할
    for (int i=-N+1;i<N;i++) {
        for (int j=0;j<N;j++) {
            if (i+j<0 || i+j>=N) continue;
            // i가 짝수일 땐 ch2, 홀수일 땐 ch1
            if (i%2==0) {
                ch2[(i+N-1)/2][j+(i/2)] = chess[j][i+j] + 1;
            }
            else {
                ch1[(i+N-1)/2][j+(i-1)/2] = chess[j][i+j] + 1;
            }
        }
    }

    // 테스트
    /*for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            printf("%d ", ch2[i][j]);
        }
        printf("\n");
    }*/

    // 각각의 판에 대해서 백트래킹 수행
    backtrackChess(0,0,0);
    backtrackChess(0,0,1);
    printf("%d", maxCh1 + maxCh2);

    return 0;
}

void backtrackChess(int x, int y, int panNum) {
    if (x >= N) {x=0; y++;}
    if (y >= N) {
        // 끝까지 왔을 때의 처리
        if (panNum) maxCh2 = max(curCh2, maxCh2);
        else maxCh1 = max(curCh1, maxCh1);
        //printf("%d %d\n", curCh1, curCh2);
        return;
    }

    if (panNum) {
        if (ch2[x][y] <= 1) {
            backtrackChess(x+1,y, panNum);
            return;
        }
    }
    else {
        if (ch1[x][y] <= 1) {
            backtrackChess(x+1,y, panNum);
            return;
        }
    }


    // 비숍을 놓을 수 있을 때, 놓을 지 안 놓을 지 백트래킹 구현
    erasedBlock.emplace(-1, -1);

    if (panNum) {
        ch2[x][y] = 1;
        curCh2++;
    }
    else {
        ch1[x][y] = 1;
        curCh1++;
    }
    erasedBlock.emplace(x, y);

    if (panNum) {
        for (int i=0;i<N;i++) {
            if (ch2[x][i] <= 1) continue;
            ch2[x][i] = 1;
            erasedBlock.emplace(x, i);
        }
        for (int i=0;i<N;i++) {
            if (ch2[i][y] <= 1) continue;
            ch2[i][y] = 1;
            erasedBlock.emplace(i, y);
        }
    }
    else {
        for (int i=0;i<N;i++) {
            if (ch1[x][i] <= 1) continue;
            ch1[x][i] = 1;
            erasedBlock.emplace(x, i);
        }
        for (int i=0;i<N;i++) {
            if (ch1[i][y] <= 1) continue;
            ch1[i][y] = 1;
            erasedBlock.emplace(i, y);
        }
    }
    backtrackChess(0,y+1, panNum);
    //backtrackChess(x+1,y, panNum);

    // 백트래킹 끝난 이후 원복 과정
    if (panNum) curCh2--;
    else curCh1--;
    while(1) {
        int revertX, revertY;
        revertX = erasedBlock.top().first;
        revertY = erasedBlock.top().second;
        erasedBlock.pop();
        if (revertX == -1) break;
        if (panNum) ch2[revertX][revertY] = 2;
        else ch1[revertX][revertY] = 2;
    }

    backtrackChess(x+1,y, panNum);
}