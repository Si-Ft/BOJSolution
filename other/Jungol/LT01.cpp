#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

int main() {
    int N;
    scanf("%d", &N);

    int maxScore = -1;
    rep(i,0,N) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int score = a*3 + b;
        if (maxScore < score) {
            maxScore = score;
        }
    }
    printf("%d\n", maxScore);

    return 0;
}