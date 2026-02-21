#include <stdio.h>
#include <algorithm>

void makeSeq (int depth, int curPos);

int visited[10] = {0,}; // 각 위치에서 방문 가능한 횟수
int N, M; // nCm, n개 자연수 중 m개 고르는 수열
int seq[10] = {0,};
int curSeq[10];

int main() {
    scanf("%d %d", &N, &M);
    for (int i=0;i<N;i++) scanf("%d", &seq[i]);

    std::sort(seq, seq+N);

    // 중복정리, visited변수 정리 한번 하자
    for (int i=0;i<N;i++) {
        visited[i] += 1;
        if (seq[i] == seq[i+1]) {
            N-=1;
            for (int j=i;j<N;j++) {
                seq[j] = seq[j+1];
                seq[j+1] = 0;
            }
            i-=1;
        }
    }

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
        if (visited[i]) { 
            visited[i] -= 1;
            makeSeq(depth+1, i);
            visited[i] += 1;
        } 
    }
}