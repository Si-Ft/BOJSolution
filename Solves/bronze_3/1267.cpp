#include <stdio.h>
#include <algorithm>
int main() {
    int N;
    scanf("%d", &N);

    int ys=0, ms=0;
    for (int i=0;i<N;i++) {
        int inp;
        scanf("%d", &inp);
        ys += (inp/30 + 1) * 10;
        ms += (inp/60 + 1) * 15;
    }
    if (ys<=ms) printf("Y ");
    if (ys>=ms) printf("M ");
    printf("%d", std::min(ys, ms));
    return 0;
}