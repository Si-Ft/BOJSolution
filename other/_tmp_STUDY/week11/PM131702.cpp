#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

/*
    도저히 풀기 힘들어서... AI의 힌트를 받았습니다
    이거 후하게줘도 골드 1 이상의 문제인데...
*/
// 좌 중 우 하 상, 첫째줄 돌릴 땐 idx==3 까지만 순회함
int dx[5] = {-1,0,1,0,0};
int dy[5] = {0,0,0,1,-1};

int solution(vector<vector<int>> clockHands) {
    int answer = 999;
    int N = clockHands.size();

    // 첫 번째 줄을 돌리는 모든 경우의 수 (4^N가지, 앞쪽부터 2비트씩 돌리는 횟수)
    rep(i,0,(1<<(2*N))) {
        vector<vector<int>> curfield(clockHands);
        int spinCount = 0;
        rep(x,0,N) {
            // 1의 배수 > x=0위치, 4의 배수 > x=1위치, 16의 배수 > x=2위치, ...
            // if (i % (1<<(2*x)) == 0) {
            //     spinCount += (i>>(2*x)) % 4;
            //     // 해당 위치에 맞는 +방향의 시곗바늘을 전부 1회 돌리기
            //     rep(k,0,4) {
            //         int cy = dy[k];
            //         int cx = x + dx[k];
            //         if (cx < 0 || cx >= N) continue;
            //         clockHands[cy][cx] = (clockHands[cy][cx]+1) % 4;
            //     }
            // }
            int spin = (i>>(2*x)) & 3;
            spinCount += spin;
            rep(k,0,4) {
                int cy = dy[k];
                int cx = x + dx[k];
                if (cx < 0 || cx >= N) continue;
                curfield[cy][cx] = (curfield[cy][cx]+spin) % 4;
            }
        }

        // 윗줄을 제외한 부분을 전부 탐색
        rep(y,1,N) {
            rep(x,0,N) {
                // 돌려야 하는 횟수
                int spin = 4 - curfield[y-1][x];
                if (spin == 4) spin = 0;
                spinCount += spin;

                // 순회하면서 돌리기
                rep(k,0,5) {
                    int cy = y + dy[k];
                    int cx = x + dx[k];
                    if (cx < 0 || cx >= N || cy >= N) continue;
                    curfield[cy][cx] = (curfield[cy][cx]+spin) % 4;
                }
            }
        }

        // 막줄 체크
        rep(x,0,N) {
            if (curfield[N-1][x] != 0) {
                spinCount = 999;
                break;
            }
        }

        answer = min(answer, spinCount);
    }

    return answer;
}