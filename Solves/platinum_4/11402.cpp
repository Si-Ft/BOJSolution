#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

long long modInverse(long long num);
long long N,M,K;

int main() {
    scanf("%lld %lld %lld",&N,&K,&M);

    // 뤼카 정리로 N이랑 K를 M으로 계속 나눔 (작은 숫자부 부터)

    int ans = 1;
    while (N>0) {
        if (N%M < K%M) {
            ans = 0;
            break;
        }
        long long curFac = 1;
        long long facN = 1, facK = 1, facNK = 1;
        rep(i,1,M) {
            curFac = curFac * i % M;
            if (i == N%M) facN = curFac;
            if (i == K%M) facK = curFac;
            if (i == N%M - K%M) facNK = curFac;
        }
        int localAns = facN;
        localAns = localAns * modInverse(facK) % M;
        localAns = localAns * modInverse(facNK) % M;

        ans = ans * localAns % M;
        N /= M;
        K /= M;
    }
    
    printf("%d\n", ans);

    return 0;
}

long long modInverse(long long num) {
    long long res = 1;
    int p = M - 2;
    while (p) {
        if (p & 1) res = res * num % M;
        num = num * num % M;
        p >>= 1;
    }
    return res;
}