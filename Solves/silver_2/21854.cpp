#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define dv 1000000007

long long pow2(int n);

int main() {
    int N;
    scanf("%d", &N);
    int ans = 0;
    rep(i,0,N) {
        int k;
        scanf("%d", &k);
        ans += pow2(k);
        ans %= dv;
    }

    printf("%d\n", ans);
    return 0;
}

long long pow2(int n) {
    if (n==0) return 1;
    if (n==1) return 2;
    if (n==2) return 4;

    long long res = pow2(n/2);
    if (n%2==0) return (res * res) % dv;
    else return (res * res * 2) % dv;
}