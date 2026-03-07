#include <stdio.h>
#include <algorithm>

int main() {
    int N;
    scanf("%d", &N);
    for (int i=0;i<N;i++) {
        int mx = 0;
        for (int j=0;j<5;j++) {
            int inp;
            scanf("%d", &inp);
            mx = std::max(mx, inp);
        }
        printf("Case #%d: %d\n", i+1, mx);
    }
    return 0;
}