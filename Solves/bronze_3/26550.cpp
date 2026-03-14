#include <stdio.h>
int main() {
    int N;
    scanf("%d", &N);
    for (int i=0;i<N;i++) {
        long long layer;
        scanf("%lld", &layer);

        long long ans=0;
        for (long long j=1;j<=layer;j++) ans += (j * (j + 1)) / 2;
        printf("%lld\n", ans);
    }

    return 0;
}