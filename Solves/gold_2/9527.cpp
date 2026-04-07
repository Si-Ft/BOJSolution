#include <stdio.h>
#define rrep(i,a,b) for(int i=a;i>=b;i--)

long long cal1count(long long n);

int main() {
    long long A,B;
    long long ans;
    scanf("%lld %lld", &A, &B);
    ans = cal1count(B);
    ans -= cal1count(A-1);
    printf("%lld", ans);

    return 0;
}

long long cal1count(long long n) {
    long long ret = 0;
    long long border = 0; // 비트 경계선 (위는 수동 계산, 아래는 자동)

    rrep(cBit,62,0) {
        if (n & 1LL<<cBit) {
            border += 1LL<<cBit;
            ret += n-border+1;
        }
        if (border == 0) continue;
        ret += (border>>cBit) / 2 * (1LL<<cBit);
    }
    return ret;
}