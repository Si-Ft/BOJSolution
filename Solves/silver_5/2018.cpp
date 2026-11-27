#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

int main() {
    int N;
    scanf("%d", &N);
    int st = 0, en = 0;
    int val = 0;
    int ans = 0;
    while (en <= N) {
        if (val == N) ans++;
        if (val < N) {
            en++;
            val += en;
        } else {
            st++;
            val -= st;
        }
    }
    printf("%d\n", ans);
    return 0;
}