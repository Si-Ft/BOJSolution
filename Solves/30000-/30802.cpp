#include <stdio.h>

int main() {
    
    int N, size[6], comb[2];
    scanf("%d", &N);
    scanf("%d %d %d %d %d %d", &size[0], &size[1], &size[2], &size[3], &size[4], &size[5]);
    scanf("%d %d", &comb[0], &comb[1]);

    int Ans1 = 0;
    for (int i = 0; i < 6; i++) Ans1 += (size[i]+comb[0]-1) / comb[0];
    
    printf("%d\n", Ans1);
    printf("%d %d", N/comb[1], N%comb[1]);

    return 0;
}