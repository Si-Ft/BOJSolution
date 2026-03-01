#include <stdio.h>
#include <algorithm>
using namespace std;

int N;
int byeoruk[100001];

int main() {
    scanf("%d", &N);
    for (int i=0;i<N;i++) scanf("%d", byeoruk + i);

    int sPos=0, ePos=0;
    long long ans=0;
    for (;sPos!=N;) {
        if (byeoruk[sPos] == 0) {
            sPos++;
            continue;
        }
        if (byeoruk[ePos] == 0) {
            ePos++;
            continue;
        }

        // 벼룩 거래 가능한 상태
        if (byeoruk[sPos]*byeoruk[ePos] < 0) {
            int deal = min(abs(byeoruk[sPos]), abs(byeoruk[ePos]));
            ans += deal * (ePos - sPos);
            if (byeoruk[sPos] >= byeoruk[ePos]) {
                byeoruk[sPos] -= deal;
                byeoruk[ePos] += deal;
            }
            else {
                byeoruk[sPos] += deal;
                byeoruk[ePos] -= deal;
            }
        }
        else ePos++;
    }

    printf("%lld", ans);

    return 0;
}