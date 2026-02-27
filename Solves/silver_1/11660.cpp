#include <stdio.h>

int nums[1025][1025] = {0}; // 0,0부터 n,n까지의 누적합

int main() {
    int N,M;
    scanf("%d %d", &N, &M);
    for (int i=1;i<=N;i++) {
        int inp;
        for (int j=1;j<=N;j++) {
            scanf("%d", &inp);
            nums[i][j] = nums[i][j-1] + nums[i-1][j] - nums[i-1][j-1] + inp;
        }
    }

    for (int i=0;i<M;i++) {
        int x1,y1,x2,y2,tot;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        tot = nums[x2][y2] - nums[x1-1][y2] - nums[x2][y1-1] + nums[x1-1][y1-1];
        printf("%d\n", tot);
    }
    return 0;
}