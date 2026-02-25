#include <stdio.h>

int main() {
    while(1) {
        int i;
        scanf("%d", &i);
        if (i==0) break;
        printf("%d\n",i*(i+1)/2);
    }
    return 0;
}