#include <stdio.h>

int main() {
    int M;
    scanf("%d", &M);

    int spins = 1;
    bool beltDirection = false;
    for (int i=0;i<M;i++) {
        int beforeSpin, afterSpin, beltType;
        scanf("%d %d %d", &beforeSpin, &afterSpin, &beltType);
        spins /= beforeSpin;
        spins *= afterSpin;
        if (beltType == 1) beltDirection = !beltDirection;
    }

    printf("%d %d", beltDirection?1:0, spins);
    return 0;
}