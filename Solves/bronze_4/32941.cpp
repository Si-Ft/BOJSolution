#include <stdio.h>

int main() {
    int T, X, N;
    scanf("%d %d %d", &T, &X, &N);

    bool isAllChamsuk = true;
    for (int i=0;i<N;i++) {
        int K;
        scanf("%d", &K);

        bool isMemberChamsuk = false;
        for (int j=0;j<K;j++) {
            int A;
            scanf("%d", &A);
            if (A == X) isMemberChamsuk = true;
        }
        if (!isMemberChamsuk) isAllChamsuk = false;
    }

    if (isAllChamsuk) printf("YES");
    else printf("NO");
    
    return 0;
}