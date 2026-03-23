#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define dv 1000000007

int modInverse(long long num);

int main() {
    int N,K;
    scanf("%d %d",&N,&K);
    int facN = 1, facK = 1, facNK = 1;
    rep(i,1,N+1) {
        facN = 1LL * facN * i % dv;
        if (i == K) facK = facN;
        if (i == N-K) facNK = facN;
    }
    int ans = facN;
    ans = 1LL * ans * modInverse(facK) % dv;
    ans = 1LL * ans * modInverse(facNK) % dv;
    printf("%d\n", ans);

    return 0;
}

int modInverse(long long num) {
    long long res = 1;
    int p = dv - 2;
    // p값을 2진수로 보고, 이분 분할정복을 이용해 계속 거듭제곱함
    while (p) {
        // 2로 안 나눠떨어지는 거듭제곱은 res로 격리
        if (p & 1) res = res * num % dv;
        num = num * num % dv;
        p >>= 1;
    }
    return res;
}