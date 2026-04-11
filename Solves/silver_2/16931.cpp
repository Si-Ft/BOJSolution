#include <stdio.h>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int blocks[100][100];

int main() {
    int N,M;
    scanf("%d %d", &N, &M);

    int ans = 0;
    rep(i,0,N) {
        rep(j,0,M) {
            scanf("%d", &blocks[i][j]);
            // 블록을 쌓았을 때, 위아래로 맞닿는 거 고려
            ans += blocks[i][j] * 4 + 2;

            if (j>0) {
                // 가로로 쌓을 때, 가로로 맞닿는 거 고려
                ans -= min(blocks[i][j], blocks[i][j-1]) * 2;
            }
            if (i>0) {
                // 세로로 쌓을 때, 세로로 맞닿는 거 고려
                ans -= min(blocks[i][j], blocks[i-1][j]) * 2;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}