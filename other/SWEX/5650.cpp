#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

void PS(int TCnum);
int simul(int sy, int sx, int cy, int cx, int dir, int score);

int main() {
    int T;
    scanf("%d", &T);
    rep(i,1,T+1) PS(i);
    
    return 0;
}

int N;
int grid[102][102];     // 필드 상태
int wormhole[16][2];    // 웜홀 탈 시 순간이동할 위치 (y,x)

// dir = 위방향 (0, 밑에서 부딪힘) > 우방향 (1, 좌측에서 부딪힘) > 하방향 (2) > 좌방향 (3)
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

// [현재 dir][만난 블럭] 값이 주어졌을 때, 업데이트할 dir (반대방향일 경우 -1 반환)
int dirquery[4][6] = {
    {0, -1, 1, 3, -1, -1},
    {1, -1, -1, 2, 0, -1},
    {2, 1, -1, -1, 3, -1},
    {3, 0, 2, -1, -1, -1}
};
// int dirquery[4][6] = {
//     {0, 2, 1, 3, 2, 2},
//     {1, 3, 3, 2, 0, 3},
//     {2, 1, 0, 0, 3, 0},
//     {3, 0, 2, 1, 1, 1}
// };


void PS(int TCnum) {
    // 초기화
    rep(i,6,16) {
        wormhole[i][0] = -1;
        wormhole[i][1] = -1;
    }

    scanf("%d", &N);
    rep(i,0,N+2) {
        rep(j,0,N+2) {
            // 벽에 border를 세움.
            if (i==0 || i==(N+1) || j==0 || j==(N+1)) {
                grid[i][j] = 5;
                continue;
            }
            int g;
            scanf("%d", &g);
            grid[i][j] = g;

            if (g <= 5) continue;
            // 웜홀 발견 시, 다른 웜홀 데이터가 없는 경우
            if (wormhole[g][0] == -1) {
                // g 위치 도착 시 출구 좌표
                wormhole[g][0] = i;
                wormhole[g][1] = j;
                // 입구 좌표 변경
                grid[i][j] += 5;
            }
            // 웜홀 발견 시, 이미 다른 웜홀이 있는 경우
            else {
                // g+5 위치 도착 시 출구 좌표
                wormhole[g+5][0] = i;
                wormhole[g+5][1] = j;
                // 입구 좌표 현행 유지
            }
        }
    }

    int ans = 0;
    rep(i,1,N+1) {
        rep(j,1,N+1) {
            if (grid[i][j] != 0) continue;
            rep(k,0,4) {
                int ret = simul(i, j, i, j, k, 0);
                if (ans < ret) ans = ret;
            }
        }
    }

    printf("#%d %d\n", TCnum, ans);
}

int simul(int sy, int sx, int tcy, int tcx, int tdir, int tscore) {
    int cy = tcy; int cx = tcx; int dir = tdir; int score = tscore;
    
    cy += dy[dir];
    cx += dx[dir];

    while(true){
        int g = grid[cy][cx]; // 액세스가 많아서 별도의 변수로 분리
        // 현위치가 블랙홀일 경우 게임 종료
        if (g == -1) return score;

        // 자기 위치로 돌아왔을 경우 즉시 게임 종료
        if (sy==cy && sx==cx) return score;

        // 직선거리일 경우, 그냥 이동
        if (g == 0) {
            cy += dy[dir];
            cx += dx[dir];
            continue;
        }

        // 웜홀일 경우 순간이동 후에 보는 방향으로 한칸 이동까지 처리
        if (g >= 6) {
            int wy = wormhole[g][0];
            int wx = wormhole[g][1];
            cy = wy+dy[dir];
            cx = wx+dx[dir];
            continue;
        }

        // 업데이트한 dir값이 반대방향으로 튕길 경우
        int newdir = dirquery[dir][g];
        if (newdir == -1) return score*2+1;

        // 정상적 이동일 경우 다음 칸으로 이동함.
        if (newdir != dir) score += 1;  // 방향이 바뀔 경우, 점수 추가
        cy += dy[newdir];
        cx += dx[newdir];
        dir = newdir;
        continue;
    }
}