#include <stdio.h>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)

void PS(int TCnum);

int main() {
    int T;
    scanf("%d", &T);
    rep(i,1,T+1) PS(i);
    
    return 0;
}

// 필드(원형)의 크기는 N
// x1: 레이무의 위치, x2: 레밀리아의 위치

/*
    레밀리아가 먼저 도망침 (최대 k번)
    레밀리아 행동 후, 레이무가 잡으러 움직임
*/
void PS(int TCnum) {
    int n, x1, x2, k;
    scanf("%d %d %d %d", &n, &x1, &x2, &k);

    
    // n개의 원형 필드에서 x1, x2의 거리 차이
    // 단, 0, n-1은 연결
    if (x1 > x2) {
        int tmp = x1;
        x1 = x2;
        x2 = tmp;
    }
    // x1 < x2, 원형 상의 두 사람의 거리
    int dist = std::min(x2-x1, x1+n-x2);

    int ans;
    if (n<=3) {
        printf("1\n");
        return;
    }
    ans = dist + k;
    printf("%d\n", ans);
}