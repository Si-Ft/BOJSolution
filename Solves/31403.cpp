#include <stdio.h>

int main(){
    int A,B,C;
    scanf("%d %d %d", &A, &B, &C);

    int sum = A+B-C;
    A*=10;
    if (B>=10) A*=10;
    if (B>=100) A*=10;
    if (B==1000) A*=10;

    printf("%d\n%d", sum, A+B-C);

    return 0;
}