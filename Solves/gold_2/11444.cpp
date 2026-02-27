#include <stdio.h>
#define dv (long long)1000000007

struct FibResult
{
    long long K0;
    long long K1;
};

FibResult fib(long long Nth);

int main() {
    long long n;
    scanf("%lld", &n);

    FibResult ans = fib(n);
    printf("%lld", ans.K0);

    return 0;
}

FibResult fib(long long Nth){
    FibResult returnValue;
    returnValue.K0 = 1;
    if (Nth == 0) {
        returnValue.K0 = 0;
        returnValue.K1 = 1;
        return returnValue;
    }
    if (Nth == 1) {
        returnValue.K1 = 1;
        return returnValue;
    }
    if (Nth == 2) {
        returnValue.K1 = 2;
        return returnValue;
    }
    
    FibResult halfValue = fib(Nth/2);

    long long k0 = halfValue.K0;
    long long k1 = halfValue.K1;

    returnValue.K0 = k0 * (2 * (k1 + dv) - k0) % dv;
    returnValue.K1 = (k1 * k1 + k0 * k0) % dv;

    if (Nth%2==1) {
        long long temp = returnValue.K1;
        returnValue.K1 = (returnValue.K0 + returnValue.K1) % dv;
        returnValue.K0 = temp;
    }

    return returnValue;
}