#include <stdio.h>
#include <algorithm>

int diff[300001];

int main() {
    int n, sum = 0;;
    scanf("%d", &n);

    for (int i=0;i<n;i++) scanf("%d", diff + i);

    if (n==0) {
        printf("0");
        return 0;
    }

    std::sort(diff,diff+n);

    int outlier = n*3/20;
    if (n*3%20 >= 10) outlier++;

    for (int i=outlier;i<n-outlier;i++) sum += diff[i];

    int rng = n - 2*outlier; // 총 유효 의견 수
    if ((sum%rng)*2>=rng) sum = sum / rng + 1;
    else sum /= rng;

    printf("%d", sum);

    return 0;
}