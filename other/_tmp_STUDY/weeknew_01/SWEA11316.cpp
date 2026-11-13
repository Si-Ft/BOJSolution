#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

void PS(int TCnum);

int main() {
    int T;
    scanf("%d", &T);
    rep(i,1,T+1) PS(i);
    
    return 0;
}

int prev[1000001];      // idx : 항 값 | value : 가장 최근에 나온 항 번호
void PS(int TCnum) {
    int s, p, q, m;     // 시작 항, 이전항에 곱할 값, 더할 값, mod 값
    scanf("%d %d %d %d", &s, &p, &q, &m);
    
    rep(i,0,1000001) prev[i] = 0;
    prev[s] = 1;

    int i = 1;  // 항 번호 (문제에선 0이지만 편의상 1번부터)
    long long cur = s;  // 현재 항 값
    while(true) {
        cur = (cur * p + q) % m;
        i++;
        if (prev[cur]) break;
        prev[cur] = i;
    }

    printf("#%d %d\n", TCnum, i - prev[cur]);
}