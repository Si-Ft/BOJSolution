#include <stdio.h>

int main() {
    int n;
    char prevfib[1003] = {0,};
    char fib[1003] = {0,};
    prevfib[1001] = 1;
    fib[1001] = 1;
    scanf("%d", &n);
    for (int i=3;i<=n;i++) {
        for (int j=1001;j>=0;j--) {
            char tmp = fib[j];
            if (fib[j+1] >= 10) {
                fib[j+1] -= 10;
                fib[j]++;
            }
            fib[j] += prevfib[j];
            prevfib[j] = tmp;
        }
    }

    bool isNumStart = false;
    for (int i=0;i<1002;i++) {
        if (fib[i]>0) isNumStart = true;
        if (isNumStart) printf("%d", fib[i]);
    }
}