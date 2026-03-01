#include <stdio.h>

int main() {
    int A,B,T=1;
    scanf("%d %d", &A, &B);
    while(A<B) {
        if (B%10==1) B/=10;
        else if (B%2==0) B/=2;
        else break;
        T++;
    }
    if (A==B) printf("%d",T);
    else printf("-1");

    return 0;
}