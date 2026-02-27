#include <stdio.h>

int main() {
    char a[35];
    scanf("%s",a);
    int diff=0;
    for (int i=0;a[i];i++) {
        diff++;
        if (a[i]==':') diff++;
        if (a[i]=='_') diff += 5;
    }
    printf("%d", diff);
    return 0;
}