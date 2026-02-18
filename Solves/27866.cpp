#include <stdio.h>

int main(){
    int i;
    char S[1001];
    scanf("%s", S);
    scanf("%d", &i);

    printf("%c\n", S[i-1]);
    return 0;
}