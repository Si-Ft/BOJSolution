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
    int N, K;
    scanf("%d %d", &N, &K);
    int kwindow = (1<<(K+1))-2; // ...001110
    int owindow = (1<<(K+2))-1; // ...011111

    // 각 줄의 값을 비트마스크로 저장
    int garo[15] = {0}; 
    int sero[15] = {0};

    rep(y,0,N) {
      rep(x,0,N) {
        int tmp;
        scanf("%d", &tmp);
        garo[y] += tmp<<(x+1);
        sero[x] += tmp<<(y+1);
      }
    }

    // 가로, 세로에서 정확히 K개의 연속된 1이 있는지 확인
    int ans = 0;
    rep(i,0,N) {
      while(garo[i]) {
        if((garo[i]&owindow) == kwindow) ans++;
        garo[i] >>= 1;
      }
      while(sero[i]) {
        if((sero[i]&owindow) == kwindow) ans++;
        sero[i] >>= 1;
      }
    }

    printf("#%d %d\n", TCnum, ans);
}