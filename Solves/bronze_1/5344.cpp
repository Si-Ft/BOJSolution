#include <stdio.h>
#include <algorithm>

int main() {
    int N;
    scanf("%d", &N);
    for (int i=0;i<N;i++) {
        int a,b;
        scanf("%d %d",&a, &b);
        if (a<b) std::swap(a,b);

        while (1)
        {
            if (a%b==0) break;
            int leftover = a%b;
            a=b;
            b=leftover;
        }

        printf("%d\n", b);
    }
    return 0;
}