#include <stdio.h>

int main() {
    int a,b;
    scanf("%d\n%d", &a, &b);
    if (a>12) a-=24;
    printf("%d", b-a);
    return 0;
}