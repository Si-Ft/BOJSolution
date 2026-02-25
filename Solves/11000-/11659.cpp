#include <stdio.h>

int main() {
    int N,M;
    int nums[100002] = {0}; // n까지의 누적합
    scanf("%d %d", &N, &M);
    for (int i=1;i<=N;i++) {
        int inp;
        scanf("%d", &inp);
        nums[i] = nums[i-1]+inp;
    }

    for (int i=0;i<M;i++) {
        int st,en,tot=0;
        scanf("%d %d", &st, &en);
        tot = nums[en]-nums[st-1];
        printf("%d\n", tot);
    }
    return 0;
}