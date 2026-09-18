#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

int N;
int arr[3][3];

bool dfs(int x, int y) {
    if (x >= N || y >= N) return false;             // 범위 밖
    if (x == N-1 && y == N-1) return true;          // 도착 지점 도달
    int jump = arr[x][y];
    if (jump == 0) return false;                    // 이동 불가 지역
    return dfs(x + jump, y) || dfs(x, y + jump);
}

int main() {
    scanf("%d", &N);
    rep(i,0,N) rep(j,0,N) scanf("%d", &arr[i][j]);

    if (dfs(0, 0)) printf("HaruHaru\n");
    else printf("Hing\n");
    return 0;
}