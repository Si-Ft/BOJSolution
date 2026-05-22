#include <stdio.h>
#define rep(i,a,b) for(int i=a;i<b;i++)

int N, M, P, F; // 선택 수, 음식 수, 단백질 요구(이상), 지방 요구(미만)
int food[10][2]; // 각각 단백질, 지방
int ans = 0;

void combi(int depth, int curIdx, int sumP, int sumF);

int main() {
    scanf("%d %d %d %d", &N, &M, &P, &F);
    
    rep(i,0,M) {
        int a, b;
        scanf("%d %d", &a, &b);
        food[i][0] = a;
        food[i][1] = b;
    }

    combi(0,0,0,0);
    printf("%d", ans);

    return 0;
}

void combi(int depth, int curIdx, int sumP, int sumF) {
    if (depth == N) {
        if (sumP >= P && sumF < F) ans++;
        return;
    }

    for (int i = curIdx; i < M; i++) {
        combi(depth + 1, i + 1, sumP + food[i][0], sumF + food[i][1]);
    }
}