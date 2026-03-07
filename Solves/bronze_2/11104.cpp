#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    for (int i=0;i<N;i++) {
        int tot = 0;
        int curMul = 16777216 / 2;
        for (int j=0;j<24;j++) {
            char a;
            scanf(" %c", &a);
            if (a == '1') tot += curMul;
            curMul /= 2;
        }
        printf("%d\n", tot);
    }
    return 0;
}