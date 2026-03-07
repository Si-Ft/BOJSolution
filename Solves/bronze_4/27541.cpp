#include <stdio.h>

int main() {
    int N;
    char joi[101];
    scanf("%d %s", &N, joi);
    if (joi[N-1] == 'G') joi[N-1] = joi[N];
    else {
        joi[N+1] = joi[N];
        joi[N] = 'G';
    }
    printf("%s", joi);
    return 0;
}