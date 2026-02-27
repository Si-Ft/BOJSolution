#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    char str1[100001], str2[100001];
    scanf("%s", str1);
    scanf("%s", str2);

    int rewritten = 0;
    for (int i=0;i<N;i++) if (str1[i] == str2[i]) rewritten++;

    printf("%d\n", rewritten);

    return 0;
}