#include <stdio.h>

int main() {
    while(1) {
        int n,s,t;
        int ans=0,prevT=0;
        scanf("%d", &n);
        if (n<0) break;
        for (int i=0;i<n;i++) {
            scanf("%d %d", &s,&t);
            ans += s*(t-prevT);
            prevT=t;
        }
        printf("%d miles\n",ans);
    }
    return 0;
}