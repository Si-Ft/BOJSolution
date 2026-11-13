#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

void PS(int TCnum);

int main() {
    int T;
    scanf("%d", &T);
    rep(i,1,T+1) PS(i);
    
    return 0;
}

void PS(int TCnum) {
    // 8*8 격자의 '.'과 'O'를 입력받는데 각 줄마다 'O'가 있는 위치를 
    // 비트마스크로 기록. 각 줄마다 'O'는 1개만 있어야만 함.
    int rowbit[8] = {0};
    bool isValid = true;
    rep(i,0,8) {
        int countO = 0;
        rep(j,0,8) {
            char c;
            scanf(" %c", &c);
            if(c == 'O') {
                rowbit[i] |= 1 << j;
                countO++;
            }
        }
        if(countO != 1) isValid = false;
    }

    int bitres = 0;
    // 각 스텝마다 비트 and연산이 0이 아니라면 겹치는 줄이 있다는 의미
    // 0이 아니라면 즉시 no 출력 후 종료, 0이라면 누적 비트로 추가
    rep(i,0,8) {
        if(bitres & rowbit[i]) {
            printf("#%d no\n", TCnum);
            return;
        }
        bitres |= rowbit[i];
    }

    // 빈 줄이 없는지 검증
    if(!isValid || bitres != (1<<8)-1) printf("#%d no\n", TCnum);
    else printf("#%d yes\n", TCnum);
}