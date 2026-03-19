#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

int main() {
    int D,K;
    int fib[30] = {1,1,};
    rep(i,2,30) fib[i] = fib[i-1] + fib[i-2];
    scanf("%d %d", &D, &K);

    int Amul=fib[D-3], Bmul=fib[D-2];
    int A=0,B;
    while (1) {
        A++;
        if ((K - A * Amul) % Bmul == 0) {
            B = (K - A * Amul) / Bmul;
            break;
        }
    }
    printf("%d\n%d", A,B);
    
    return 0;   
}