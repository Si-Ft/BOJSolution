#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

void PS(int TCnum);

int main() {
    int T;
    scanf("%d", &T);
    rep(i,1,T+1) PS(i);
    
    return 0;
}

/*
    idx 1 : 마지막 위치에서 보고 있는 4방향 (시계방향)
        상:0, 우:1, 하:2, 좌:3
    idx 2 : 보석 위치의 상대적 대각 4방향 (역N방향)
        우상:0, 우하:1, 좌상:2, 좌하:3
    output : 최소 turn 수

    계산 근거 : 보석은 지도의 가장자리에 나타나지 않음 -> 계산 공식에 벽으로 인한 변수 X
        또한 연속된 두 보석은 같은 행/열에 나타나지 않음 -> 직선조건 무시 가능
*/
int turnQuery[4][4] = {
    {1, 2, 3, 3},
    {3, 1, 3, 2},
    {3, 3, 2, 1},
    {2, 3, 1, 3}
};

void PS(int TCnum) {
    int N;
    int jewel[12][2] = {0}; // 보석 위치의 y, x좌표
    scanf("%d", &N);
    rep(i,0,N) {
        rep(j,0,N) {
            int tmp;
            scanf("%d", &tmp);
            // 보석 위치 인덱스로 저장
            if (tmp > 0) {
                jewel[tmp][0] = i;
                jewel[tmp][1] = j;
            }
        }
    }

    int dir = 1;
    int ans = 0;
    for (int i=1; jewel[i][0] != 0; i++) {
        // 다음 보석의 상대적 대각 위치
        int jdir = (jewel[i-1][1] > jewel[i][1])?2:0;
        jdir += (jewel[i-1][0] < jewel[i][0])?1:0;

        // 턴 해야 하는 횟수
        int udir = turnQuery[dir][jdir];
        ans += udir;
        dir = (dir+udir)%4;
    }

    printf("#%d %d\n", TCnum, ans);
}

