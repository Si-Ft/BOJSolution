#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

int grid[100][100] = {0};

int main() {
    int N, M;   // 케이스 수, 겹쳐야하는 수
    scanf("%d %d", &N, &M);
    rep(i,0,N) {
        int sx, sy, ex, ey;
        scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
        rep(x, sx-1, ex) {
            rep(y, sy-1, ey) {
                grid[x][y]++;
            }
        }
    }
    int cnt = 0;
    rep(x,0,100) {
        rep(y,0,100) {
            if(grid[x][y] > M) cnt++;
        }
    }

    printf("%d", cnt);
    return 0;
}