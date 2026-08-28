#include <stdio.h>
#include <stdbool.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

int main() {
    int N;
    scanf("%d", &N);

    bool impossible[1000] = {false};
    rep(i, 0, 1000) {
        // 123 미만의 수는 불가능 (조건이 세 자리 이상 + 0 미포함 + 자리 다른 수)
        if (i < 123) { impossible[i] = true; continue; }
        
        // 0이 포함된 수는 불가능
        int n1 = i % 10;            // 일의자리
        int n2 = (i / 10) % 10;     // 십의자리
        int n3 = i / 100;           // 백의자리
        if (n1 == 0 || n2 == 0) { impossible[i] = true; continue; }

        // 100 이상의 수 중에서 각 자리가 모두 다른 수만 가능
        if (n3 == n2 || n3 == n1 || n2 == n1) {
            impossible[i] = true;
            continue;
        }
    }
    rep(i,0,N) {
        int guess, s, b;
        scanf("%d %d %d", &guess, &s, &b);

        int g1 = guess % 10;            // 일의자리
        int g2 = (guess / 10) % 10;     // 십의자리
        int g3 = guess / 100;           // 백의자리

        // 모든 현재 가능한 수를 순회하여 조건에 맞는 수만 남김
        rep (j,123,1000) {
            if (impossible[j]) continue;
            int c1 = j % 10;            // 일의자리
            int c2 = (j / 10) % 10;     // 십의자리
            int c3 = j / 100;           // 백의자리

            int strike = 0, ball = 0;
            // 스트라이크 판정
            if (g1 == c1) strike++;
            if (g2 == c2) strike++;
            if (g3 == c3) strike++;

            // 볼 판정
            if (g1 == c2 || g1 == c3) ball++;
            if (g2 == c1 || g2 == c3) ball++;
            if (g3 == c1 || g3 == c2) ball++;

            // 조건과 일치하지 않으면 불가능
            if (strike != s || ball != b) {
                impossible[j] = true;
            }
        }
    }

    int ans = 0;
    rep(i,123,1000) {
        if (!impossible[i]) ans++;
    }
    printf("%d\n", ans);

    return 0;
}