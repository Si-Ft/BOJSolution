#include <stdio.h>
#include <algorithm>

int main() {
    int M,H,N;
    scanf("%d %d %d", &M, &H, &N);
    int tot = 0;
    int C,B;
    for (int i=0;i<N;i++) {
        scanf("%d %d", &C, &B);
        tot += std::max(C*M, B*H);
    }
    printf("%d", tot);
    return 0;
}