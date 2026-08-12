#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

void PS(int TCnum);

int main() {
    int T;
    scanf("%d", &T);
    rep(i,1,T+1) PS(i);
    
    return 0;
}

int dy[4] = {0,0,1,1};
int dx[4] = {0,1,0,1};
void PS(int TCnum) {
    int R,C;
    scanf("%d %d", &R, &C);
    char tile[51][51];
    rep(y,0,R) rep(x,0,C) scanf(" %c", &tile[y][x]);
    rep(y,0,R) rep(x,0,C) {
        if (tile[y][x] == '#') {
            rep(i,0,4) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                // 타일 대체 불가능
                if (ny >= R || nx >= C || tile[ny][nx] == '.') {
                    printf("#%d NO\n", TCnum);
                    return;
                }
                tile[ny][nx] = '.';
            }
        }
    }
    printf("#%d YES\n", TCnum);
}