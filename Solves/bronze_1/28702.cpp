#include <stdio.h>
#include <stdlib.h>

int main() {
    char inp[10];
    int curNum=0;
    for (int i=0;i<3;i++) {
        scanf("%s", inp);
        if (inp[0] < 60) curNum = atoi(inp);
        curNum++;
    }

    if (curNum % 3 == 0) printf("Fizz");
    if (curNum % 5 == 0) printf("Buzz");
    if ((curNum % 3 == 0) || (curNum % 5 == 0)) return 0;

    printf("%d", curNum);
    return 0;
}