#include <stdio.h>
#include <vector>
#include <queue>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int main() {
    int TC;
    scanf("%d", &TC);
    rep(tc,0,TC) {
        int N,K; // 건물의 개수, 간선 개수
        int D[1001]; // i번 건물을 짓는 데 걸리는 시간
        vector<vector<int>> buildSeq(1001); // 간선 저장
        int beforeConstruct[1001] = {0}; // 앞에 더 지어야 하는 건물 수
        int constructMinTime[1001]; // i번 건물 건설까지 걸리는 최소 시간
        queue<int> nextConstruct; // 다음에 지을 건물 번호

        scanf("%d %d", &N, &K);
        rep(i,0,N) {
            scanf("%d", D+i+1);
            constructMinTime[i+1] = D[i+1];
        }
        rep(i,0,K) {
            int X,Y;
            scanf("%d %d", &X, &Y);
            buildSeq[X].push_back(Y);
            beforeConstruct[Y]++;
        }

        int W; // 건설해야 하는 건물 번호
        scanf("%d", &W);

        // 건설 순서에 따라 constructMinTime 계산
        rep(i,1,N+1) {
            if (beforeConstruct[i] != 0) continue;
            nextConstruct.push(i);
            constructMinTime[i] = D[i];
        }
        while (!nextConstruct.empty()) {
            int current = nextConstruct.front();
            nextConstruct.pop();

            for (int next : buildSeq[current]) {
                beforeConstruct[next]--;
                constructMinTime[next] = max(constructMinTime[next], constructMinTime[current] + D[next]);
                if (beforeConstruct[next] == 0) {
                    nextConstruct.push(next);
                }
            }
        }
        printf("%d\n", constructMinTime[W]);

    }
    return 0;
}