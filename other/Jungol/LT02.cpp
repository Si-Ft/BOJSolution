#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

int main() {
    double a, b;
    scanf("%lf %lf", &a, &b);
    char c;
    scanf(" %c", &c);
    printf("%.2lf\n%.2lf\n%c", a, b, c);
    return 0;
}