#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

int main() {
    int M;
    scanf("%d", &M);
    int ans = 1;
    rep(i,0,M) {
        int X,Y;
        scanf("%d %d", &X, &Y);
        if (X == ans) {
            ans = Y;
        } else if (Y == ans) {
            ans = X;
        }
    }
    printf("%d\n", ans);
    return 0;
}