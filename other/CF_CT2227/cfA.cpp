#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

int main() {
    int N;
    scanf("%d", &N);
    rep(i,0,N) {
        int a,b;
        scanf("%d %d", &a, &b);
        if (a%2 == 1 && b%2 == 1) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}