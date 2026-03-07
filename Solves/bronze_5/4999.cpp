#include <stdio.h>
#include <string.h>

int main() {
    char ah[1000], ah2[1000];
    scanf("%s", ah);
    scanf("%s", ah2);
    if (strlen(ah) < strlen(ah2)) printf("no");
    else printf("go");
    return 0;
}