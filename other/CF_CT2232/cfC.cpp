#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

void PS(int TCnum);
int process(int maxA);

int main() {
    int T;
    scanf("%d", &T);
    rep(i,1,T+1) PS(i);
    
    return 0;
}

int N, tables, seats;
char friends[200001];

void PS(int TCnum) {
    scanf("%d %d %d ", &N, &tables, &seats);
    scanf("%s", friends);

    int ans = 0;
    int lp = 0, rp = N*2;
    while(lp <= rp) {
        int mid = (lp+rp)/2;

        int pc1 = process(mid);
        int pc2 = process(mid+1);
        if (ans < pc1) ans = pc1;
        if (ans < pc2) ans = pc2;

        // 같을 경우 : 수 내려야함. pc1 < pc2 올려야함 pc1 > pc2 내려야함
        if (pc1 >= pc2) rp = mid;
        else lp = mid + 1;
    }
    printf("%d\n", ans);
}

int process(int maxA) {
    int leftT = tables;     // 남은 테이블
    int leftS = 0;          // 이미 사람이 있는 남은 좌석
    int ans = 0;            // 좌석에 앉은 사람

    rep(i,0,N) {
        char P = friends[i];

        if (P == 'E' && leftS > 0) { // 이미 사람이 있는 테이블에 배정함
            ans++;
            leftS--;
        }
        if (P == 'I' && leftT > 0) { // 사람이 없는 테이블에 배정함
            ans++;
            leftT--;
            leftS += (seats - 1);
        }
        if (P == 'A') {
            // maxA가 있다면, 새 테이블에 배정. 없다면 다음 케이스
            if (maxA > 0 && leftT > 0) {
                ans++;
                leftT--;
                leftS += (seats - 1);
                maxA--;
            }
            // maxA가 소진되었다면 이미 사람이 있는 테이블에 배정
            else if (leftS > 0) {
                ans++;
                leftS--;
            }
        }
    }

    return ans;
}