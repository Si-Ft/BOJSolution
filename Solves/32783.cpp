#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

long long useEl[201];

int main() {
    int n;
    scanf("%d", &n);
    rep(i,0,n) {
        int a,m;
        scanf("%d %d", &a, &m);
        a /= 250;
        m /= 15;
        useEl[i] = 1LL*a*m*6;
    }
    return 0;
}