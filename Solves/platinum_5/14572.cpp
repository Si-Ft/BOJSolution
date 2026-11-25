#include <stdio.h>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

struct Student {
    int power;
    bool know[30] = {false};
};

int N, K, D;
Student stud[100000];

int main() {
    scanf("%d %d %d", &N, &K, &D);
    rep(i,0,N) {
        int cnt;
        scanf("%d %d", &cnt, &stud[i].power);
        rep(j,0,cnt) {
            int subject;
            scanf("%d", &subject);
            stud[i].know[subject-1] = true;
        }
    }

    // 실력 기준 오름차순 정렬
    sort(stud, stud+N, [](const Student &a, const Student &b) {
        return a.power < b.power;
    });

    int maxE = 0;           // 최대 효율성
    int st = 0, en = -1;    // 투 포인터
    int knows[30] = {0};
    while(true) {
        // 1. en포인터를 실력 차이가 D 초과하는 순간 전까지 이동
        while((en+1 < N) && (stud[en+1].power - stud[st].power <= D)) {
            en++;
            rep(i,0,K) if (stud[en].know[i]) knows[i]++;
        }

        // 2. 효율성 계산 (범위가 0개일 경우 이건 스킵)
        if (st <= en) {
            // knows가 1 이상 mcnt "미만"인 과목 수 세기
            int mcnt = en - st + 1;
            int kcnt = 0;
            rep(i,0,K) if (knows[i] > 0 && knows[i] < mcnt) kcnt++;
            maxE = max(maxE, mcnt*kcnt);
        }

        // 3. en 포인터 +1 늘리기 (여기서 en이 범위 초과시 종료)
        en++;
        if (en >= N) break;
        rep(i,0,K) if (stud[en].know[i]) knows[i]++;

        // 4. 실력 차이가 D 범위가 될 때까지 st 포인터 이동
        while(stud[en].power - stud[st].power > D) {
            rep(i,0,K) if (stud[st].know[i]) knows[i]--;
            st++;
        }
    }

    printf("%d\n", maxE);
    return 0;
}