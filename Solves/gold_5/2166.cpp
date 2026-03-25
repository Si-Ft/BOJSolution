#include <stdio.h>
#include <stdlib.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

int main() {
    int N;
    long long ix, iy;
    long long x[2], y[2];
    long long plusFactor=0, minusFactor=0;
    scanf("%d", &N);
    rep(i,0,N) {
        scanf("%lld %lld", &x[i%2], &y[i%2]);
        if (i==0) {
            ix = x[0];
            iy = y[0];
            continue;
        }
        plusFactor += x[(i+1)%2] * y[i%2];
        minusFactor += x[i%2] * y[(i+1)%2];
        if (i==(N-1)) {
            plusFactor += x[i%2] * iy;
            minusFactor += ix * y[i%2];
        }
    }
    long long ans = abs(plusFactor-minusFactor);
    printf("%lld", ans/2);
    if ((ans%2) == 0) printf(".0");
    else printf(".5");
    return 0;
}