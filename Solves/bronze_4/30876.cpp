#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int mX=1001, mY=1001;
    for (int i=0;i<N;i++) {
        int x,y;
        scanf("%d %d", &x, &y);
        if (mY > y) {
            mX = x;
            mY = y;
        }
    }
    printf("%d %d", mX, mY);

    return 0;
}