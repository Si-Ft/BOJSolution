#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

long long shiftleft(long long num, int idx) {
    // num의 0~idx번째 까지의 1의 개수
    int onecnt = 0;

    for (int i=0; i<idx; i++) {
        if ((num & (1LL << i)) > 0) onecnt++;
    }

    num >>= idx;
    for (int i=0; i<idx; i++) {
        num <<= 1;
        if (onecnt > 0) {
            num |= 1;
            onecnt--;
        }
    }

    return num;
}

long long shiftright(long long num, int idx) {
    // num의 0~idx번째 까지의 0의 개수
    int zerocnt = 0;

    for (int i=0; i<idx; i++) {
        if ((num & (1LL << i)) == 0) zerocnt++;
    }

    num >>= idx;
    for (int i=0; i<idx; i++) {
        num <<= 1;
        if (zerocnt > 0) {
            zerocnt--;
            continue;
        }
        num |= 1;
    }

    return num;
}

int main() {

    long long A;
    scanf("%lld", &A);
    long long ansMin = 0;
    long long ansMax = 0;
    int found = 0;

    for (int i=0; i<63; i++) {
        long long lb = 1LL << (i+1);    // 왼쪽비트
        long long rb = 1LL << i;        // 오른쪽비트

        // 왼쪽은 1, 오른쪽은 0인 경우
        if ((A & lb) > 0 && (A & rb) == 0) {
            // 추가할 것
            ansMin = A - lb + rb;
            ansMin = shiftleft(ansMin, i);
            found |= 1;
        }

        // 왼쪽은 0, 오른쪽은 1인 경우
        if ((A & lb) == 0 && (A & rb) > 0) {
            ansMax = A + lb - rb;
            ansMax = shiftright(ansMax, i);
            found |= 2;
        }

        if (found == 3) break; // 둘다 찾았으면 종료
    }

    printf("%lld %lld", ansMin, ansMax);

    return 0;
}