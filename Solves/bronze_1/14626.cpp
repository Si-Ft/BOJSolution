#include <stdio.h>

int main() {
    char isbn[15];
    scanf("%s", isbn);
    int numTot = 0, mult;
    int X[2] = {1,3};
    for (int i=0;i<13;i++) {
        if (isbn[i]=='*') {
            mult = X[i%2];
            continue;
        }
        numTot += (isbn[i]-48) * X[i%2];
    }
    int ans=0;
    while (numTot%10) {
        numTot += mult;
        ans++;
    }
    printf("%d", ans);
    return 0;
}