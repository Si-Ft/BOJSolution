#include <stdio.h>
#include <unordered_set>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int board[9][9];
unordered_set<int> garo_line[9];
unordered_set<int> sero_line[9];
unordered_set<int> square[3][3];

bool termin = false;
void backtrack(int y, int x);

int main() {
    rep(i,0,9) {
        rep(j,0,9) {
            char inp;
            scanf(" %c", &inp);
            board[i][j] = inp - '0';
            if (board[i][j] == 0) continue;

            garo_line[i].insert(board[i][j]);
            sero_line[j].insert(board[i][j]);
            square[i/3][j/3].insert(board[i][j]);
        }
    }

    // 백트래킹 시작
    backtrack(0,0);

    rep(i,0,9) {
        rep(j,0,9) {
            printf("%d", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void backtrack(int y, int x) {
    if (x>=9) {y++; x=0;}
    if (y>=9) {
        // 백트래킹 완료
        termin = true;
        return;
    }

    // 빈 칸이 아닐 경우 스킵
    if (board[y][x] != 0) {
        backtrack(y,x+1);
        return;
    }

    // 수 하나씩 넣어보기
    rep(i,1,10) {
        if (garo_line[y].count(i)) continue;
        if (sero_line[x].count(i)) continue;
        if (square[y/3][x/3].count(i)) continue;

        garo_line[y].insert(i);
        sero_line[x].insert(i);
        square[y/3][x/3].insert(i);
        board[y][x] = i;

        backtrack(y,x+1);
        if (termin) return;

        garo_line[y].erase(i);
        sero_line[x].erase(i);
        square[y/3][x/3].erase(i);
        board[y][x] = 0;
    }
}