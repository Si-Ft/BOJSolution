#include <stdio.h>
#include <algorithm>

void makeSeq (int depth, int curPos);

bool visited[10] = {false, };
int N, M; // nCm, n개 자연수 중 m개 고르는 수열
int seq[10];
int curSeq[10];

int main() {
    scanf("%d %d", &N, &M);
    for (int i=0;i<N;i++) scanf("%d", &seq[i]);

    std::sort(seq, seq+N);
    makeSeq(0,0);

    return 0;
}

void makeSeq (int depth, int curPos) {
    curSeq[depth] = curPos;

    if (depth == M) { // 여기서 여태 만들어진 수열 출력
        for (int i=1;i<=M;i++) printf("%d ", seq[curSeq[i]]);
        printf("\n");
        return;
    }

    for (int i=0;i<N;i++) {
        if (!visited[i]) { 
            visited[i] = true;
            makeSeq(depth+1, i);
            visited[i] = false;
        } 
    }
}