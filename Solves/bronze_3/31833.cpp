#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    long long A=0, B=0;
    for (int i=0;i<N;i++) {
        int input;
        scanf("%d", &input);
        A*=10;
        if (input >= 10) A*=10;
        A+=input;
    }
    for (int i=0;i<N;i++) {
        int input;
        scanf("%d", &input);
        B*=10;
        if (input >= 10) B*=10;
        B+=input;
    }
    if (A > B) printf("%lld", B);
    else printf("%lld", A);
    return 0;
}